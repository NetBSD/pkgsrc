#! /bin/sh

# Copyright (c) 2026 Alistair Crooks <agc@NetBSD.org>
# All rights reserved.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
#
# THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
# IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
# OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
# IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
# INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
# NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
# DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
# THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
# (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
# THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
# Usage: depgraph [-V] [-v] [pkg...]

DEPGRAPH_VERSION=20260319

case "$(uname -s)" in
NetBSD)
	PATH=$(sysctl -n user.cs_path)
	export PATH
	;;
esac

# some defaults for running this
json=false
license=false
nameversion=false
metadata=false

# find the path for the program/utility $2
# set $1 with that information
# taken from pkgsrc bootstrap
which_prog()
{
	_var="$1"; _name="$2"

	eval _tmp=\"\$$_var\"
	if [ "x$_tmp" != "x" ]; then
		# Variable is already set (by the user, for example)
		return 0
	fi

	for _d in `echo $PATH | tr ':' ' '`; do
		if [ -f "$_d/$_name" ] && [ -x "$_d/$_name" ]; then
			# Program found
			eval $_var=\""$_d/$_name"\"
			return 1
		fi
	done

	die "$_name not found in path."
}

# get the correct programs
which_prog awk awk
which_prog date date
which_prog pkg_info pkg_info
which_prog sed sed
which_prog sort sort
which_prog uname uname
which_prog uptime uptime

# print json pkg info
pkg_print_json() {
	local name="$1"
	local lic="$2"

	printf "{\"package\":\"%s\"" "${s}"
	if ${license}; then
		printf ",\"license\":\"%s\"" "${lic}"
	fi
}

# print normal pkg info
pkg_print_normal() {
	local bar="$1"
	local str="$2"
	local s="$3"
	local lic="$4"

	printf "%s%s%s%s\n" "${bar}" "${str}" "${s}" "${lic}"
}

# print info for a package, recursing when pre-reqs are found
dopkg() {
	local name="$1"
	local str="$2"
	local prereq=0

	case "${name}" in
	"")	;;
	*)
		case "${str}" in
		"")	bar="" ;;
		*)	bar="|" ;;
		esac
		if ${license}; then
			lic="$(pkg_info -Q LICENSE ${name})"
			if ! ${json}; then
				lic=" (${lic})"
			fi
		else
			lic=""
		fi
		if ${nameversion}; then
			s=$(${pkg_info} -e "${name}")
		else
			s="${name}"
		fi
		if ${json}; then
			pkg_print_json "${s}" "${lic}"
		else
			pkg_print_normal "${bar}" "${str}" "${s}" "${lic}"
		fi
		str="${str}--"
		# we do the sort -u here because sometimess packages have duplicate REQUIRES in them
		# Information for clang-19.1.7nb2:
		# Requires:
		# llvm-19.1.7{,nb*}
		# llvm>=19.1.7
		deps=$(${pkg_info} -nq "${name}" | \
			${sed} -E -e 's/(>=.*|\-\[0\-9\]\*|\-[0-9.]+)(\{.*\})?$//' | \
			${sort} -u)
		for dep in ${deps}; do
			if ${json}; then
				printf ",\"prereq%d\":" "${prereq}"
			fi
			dopkg "${dep}" "${str}"
			prereq=$(( prereq + 1 ))
		done
		if ${json}; then
			printf "}"
		fi
		;;
	esac
}

# process any options
while getopts "Vajlmvx" a; do
	case "$a" in
	V)	printf "depgraph-%s\n" "${DEPGRAPH_VERSION}"; exit 0 ;;
	a)	license=true
		metadata=true
		nameversion=true
		;;
	j)	json=true ;;
	l)	license=true ;;
	m)	metadata=true ;;
	v)	nameversion=true ;;
	x)	set -x ;;
	*)	printf "Unknown option: \"${a}\"" >&2; exit 2 ;;
	esac
done
shift $((OPTIND - 1))

if ${metadata}; then
	mach="$(${uname} -a)"
	t="$(${date} -u)"
	localbase="$(${pkg_info} -Q LOCALBASE digest)"
	up="$(${uptime})"
	if ${json}; then
		printf "{\"Report version\":\"%s\",\"metadata\":\"%s\",\"date\":\"%s\",\"localbase\":\"%s\",\"uptime\":\"%s\"}" \
			"${DEPGRAPH_VERSION}" "${mach}" "${t}" "${localbase}" "${up}"
	else
		printf "# Report version: %s\n# Machine metadata: %s\n# Date run: %s\n# localbase: %s\n# uptime: %s\n" \
			"${DEPGRAPH_VERSION}" "${mach}" "${t}" "${localbase}" "${up}"
	fi
fi

# if no packages specified, then do for all user-installed packages
if [ $# -eq 0 ]; then
	# force name and version for all of the sub packages
	for i in $(${pkg_info} -u | ${awk} '{ print $1 }'); do
		base=$(echo $i | ${sed} -E -e 's/\-[0-9.a-z]*((p|pl|nb)[0-9]+)?$//')
		dopkg "$base" ""
	done
else
	while [ $# -gt 0 ]; do
		dopkg "$1" ""
		shift
	done
fi

exit 0
