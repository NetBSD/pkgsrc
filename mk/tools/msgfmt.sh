#!/bin/sh
#
# $NetBSD: msgfmt.sh,v 1.3 2006/04/14 13:40:07 jlam Exp $
#
# Copyright (c) 2006 The NetBSD Foundation, Inc.
# All rights reserved.
#
# This code is derived from software contributed to The NetBSD Foundation
# by Johnny C. Lam.
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in the
#    documentation and/or other materials provided with the distribution.
# 3. All advertising materials mentioning features or use of this software
#    must display the following acknowledgement:
#        This product includes software developed by the NetBSD
#        Foundation, Inc. and its contributors.
# 4. Neither the name of The NetBSD Foundation nor the names of its
#    contributors may be used to endorse or promote products derived
#    from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#
#
# Copyright (c) 2004, 2005, 2006 Julio M. Merino Vidal <jmmv@NetBSD.org>
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in
#    the documentation and/or other materials provided with the
#    distribution.
# 3. Neither the name of author nor the names of its contributors may
#    be used to endorse or promote products derived from this software
#    without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.

: ${AWK=awk}
: ${MSGFMT=/usr/bin/msgfmt}

case "${MSGFMT}" in
/*)	;;
*)	echo 1>&2 "$0: \`\`${MSGFMT}'' must be an absolute pathname."
	exit 1
	;;
esac
if test ! -x "${MSGFMT}"; then
	echo 1>&2 "$0: \`\`${MSGFMT}'' does not exist."
	exit 1
fi

# Parse the command line options.
version=
pofile=
cmd="${MSGFMT}"
while test $# -gt 0; do
	case "$1" in
	--version)
		version="$1"
		cmd="$cmd $1"; shift
		;;
	-[aDo]|--alignment|--directory|--output-file)
		cmd="$cmd $1 $2"; shift; shift;
		;;
	[!-]*)
		pofile="$1"
		cmd="$cmd -"; shift
		;;
	*)
		cmd="$cmd $1"; shift
		;;
	esac
done

# If we are asked for just the version, then avoid spawning awk.
test -z "$version" || exec $cmd
test -n "$pofile" || exec $cmd

cat $pofile | ${AWK} '
{
	s = 0
	p = 0
	
	sub("^#~", "")

	# Buffer any "msgid" statements into the singular array.
	if ($0 ~ /^msgid[ 	]+/) {
		sub("^msgid[ 	]+", "");
		singular[s++] = $0
		while (getline) {
			if ($0 ~ /^$/) continue
			if ($0 ~ /^[ 	]*"/)
				singular[s++] = $0
			else
				break
		}
	}

	# Buffer any "msgid_plural" statements into the plural array.
	if ($0 ~ /^msgid_plural[ 	]+/) {
		sub("^msgid_plural[ 	]+", "");
		plural[p++] = $0
		while (getline) {
			if ($0 ~ /^[ 	]*"/)
				plural[p++] = $0
			else
				break
		}
	}

	# If we see "msgstr", then we are outputting the translation
	# of a singular form of a message, so dump the contents of the
	# singular array and output the "msgstr" translation.
	#
	if ($0 ~ /^msgstr[ 	]+/) {
		sub("^msgstr[ 	]+", "");
		if (s > 0) {
			print "msgid " singular[0]
			for (i = 1; i < s; i++) print singular[i]
		}
		print "msgstr " $0
		while (getline) {
			if ($0 ~ /^[ 	]*"/)
				print $0
			else
				break
		}
	}

	# If we see "msgstr[0]", then we are outputting the translation
	# of a singular form of a message, so dump the contents of the
	# singular array and output the "msgstr[0]" translation.
	#
	if ($0 ~ /^msgstr\[0\][ 	]+/) {
		sub("^msgstr...[ 	]+", "");
		if (s > 0) {
			print "msgid " singular[0]
			for (i = 1; i < s; i++) print singular[i]
		}
		print "msgstr " $0
		while (getline) {
			if ($0 ~ /^[ 	]*"/)
				print $0
			else
				break
		}
	}

	# If we see "msgstr[1]", then we are outputting the translation
	# of a plural form of a message, so dump the contents of the
	# plural array and output the "msgstr[1]" translation.
	#
	if ($0 ~ /^msgstr\[1\][ 	]+/) {
		#
		# Check if the singular and plural arrays are equal.
		# If they are, then we do not need to output an
		# additional plural translation at all since the
		# "singular" form is already correct.
		#
		equal = 0
		if (s == p) {
			equal = 1;
			for (i = 0; i < s; i++) {
				if (singular[i] != plural[i]) {
					equal = 0; break
				}
			}
		}
		if (equal == 1) {
			while (getline) {
				if ($0 !~ /^[ 	]*"/) break
			}
			s = 0; p = 0
			next
		}

		sub("^msgstr...[ 	]+", "");
		if (p > 0) {
			print "msgid " plural[0]
			for (i = 1; i < p; i++) print plural[i]
		}
		print "msgstr " $0
		while (getline) {
			if ($0 ~ /^[ 	]*"/)
				print $0
			else
				break
		}
	}

	# Skip comments and blank lines.
	if ($0 ~ /^#/ || $0 ~ /^[ 	]*$/) {
		print $0
		next
	}
}
' | $cmd
