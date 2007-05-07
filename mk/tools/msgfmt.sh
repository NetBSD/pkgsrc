#!/bin/sh
#
# $NetBSD: msgfmt.sh,v 1.27 2007/05/07 09:31:05 obache Exp $
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
#

# If you make changes to this file, please test that it can process all
# of the *.po files in each of the following packages:
#
#	databases/libgnomedb
#	devel/libgnome
#	fonts/fontforge
#	multimedia/gmencoder
#	multimedia/gnome2-media
#	net/gtk-gnutella
#	sysutils/gnome-vfs2
#	wm/icewm
#	www/epiphany
#	x11/matchbox-panel
#

: ${AWK=awk}
: ${CAT=cat}
: ${MSGFMT=/usr/bin/msgfmt}
: ${TEE=tee}

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
debug=
cmd="${MSGFMT}"
while test $# -gt 0; do
	case "$1" in
	--debug)
		debug=yes; shift
		;;
	--version)
		version="$1"
		cmd="$cmd $1"; shift
		;;
	-[aDo]|--alignment|--directory|--output-file)
		cmd="$cmd $1 $2"; shift; shift;
		;;
	-c)
		# skip all checks
		shift
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

# If --debug is specified, then dump the output from the awk script
# to $pofile.debug along the way.
#
if test -z "$debug"; then
	debug="${CAT}"
else
	debug="${TEE} $pofile.debug"
fi

# If the input file cannot be found as named, then also search for a file
# with the same name that ends in ".po".
#
if test "$pofile" != "-" -a ! -e "$pofile"; then
	popofile=""
	for extension in po pot; do
		if test -e "$pofile.$extension"; then
			popofile="$pofile.$extension"
			break;
		fi
	done
	if test "x$popofile" = "x"; then
		echo 1>&2 "$0: error while opening \"$pofile\" for reading: No such file or directory"
		exit 1
	fi
	pofile="$popofile"
fi

${CAT} $pofile | ${AWK} '
#
# strip_bad_ctrl_sequences(string)
#	If we see \c, where c is anything but a legal character as
#	defined by msgfmt-0.10.35, then replace the backslash with a
#	'?'.  Yes, this is a hack, but it works around a bug in the
#	way that older msgfmt mis-identifies some "control" sequences.
#
function strip_bad_ctrl_sequences(string,	left, right) {
	left = ""
	right = string
	while (match(right, /\\/) > 0) {
		if (substr(right, RSTART + 1, 1) ~ /[bfnrtxX0-7"\\]/) {
			left = left substr(right, 1, RSTART + 1)
			right = substr(right, RSTART + 2)
		} else {
			left = left substr(right, 1, RSTART - 1) "?"
			right = substr(right, RSTART + 1)
		}
	}
	return left right
}

BEGIN {
	EMPTY = "^$"
	SPACE = "[ 	]*"
	KEYWORD_SEP = "([ 	]+|[ 	]*\"|$)"
	OBSOLETE = "#~ "
	OBSOLETE_RE = "^(#~[ 	]+)?[ 	]*"
	OBSOLETE_RE_MATCH = "^#~[ 	]+"
	MSG_CONTINUATION_RE = OBSOLETE_RE "\""

	result = getline
	if (result < 1) exit result

	s = 0
	p = 0
	obsolete = ""

	while (result == 1) {

		# Buffer any "msgid" statements into the singular array.
		# Strip all trailing empty strings that have no effect on
		# the output.
		#
		MSGID_RE = OBSOLETE_RE "msgid"
		if ($0 ~ MSGID_RE KEYWORD_SEP) {
			obsolete = ""
			if ($0 ~ OBSOLETE_RE_MATCH) obsolete = OBSOLETE
			sub(MSGID_RE SPACE, "");
			s = 0
			if ($0 ~ EMPTY) $0 = "\"\""
			$0 = strip_bad_ctrl_sequences($0)
			singular[s++] = $0
			while (result = getline) {
				if ($0 ~ OBSOLETE_RE "$") continue
				if ($0 !~ MSG_CONTINUATION_RE) break
				sub(OBSOLETE_RE , "")
				$0 = strip_bad_ctrl_sequences($0)
				singular[s++] = $0
			}
			if (result < 0) break
			while ((s > 1) && (singular[s-1] ~ /^""$/)) s--
			continue
		}

		# Buffer any "msgid_plural" statements into the plural
		# array.  Strip all trailing empty strings that have no
		# effect on the output.
		#
		MSGID_PLURAL_RE = OBSOLETE_RE "msgid_plural"
		if ($0 ~ MSGID_PLURAL_RE KEYWORD_SEP) {
			obsolete = ""
			if ($0 ~ OBSOLETE_RE_MATCH) obsolete = OBSOLETE
			sub(MSGID_PLURAL_RE SPACE, "");
			p = 0
			if ($0 ~ EMPTY) $0 = "\"\""
			$0 = strip_bad_ctrl_sequences($0)
			plural[p++] = $0
			while (result = getline) {
				if ($0 ~ OBSOLETE_RE "$") continue
				if ($0 !~ MSG_CONTINUATION_RE) break
				sub(OBSOLETE_RE, "")
				$0 = strip_bad_ctrl_sequences($0)
				plural[p++] = $0
			}
			if (result < 0) break
			while ((p > 1) && (plural[p-1] ~ /^""$/)) p--
			continue
		}

		# If we see "msgstr", then we are outputting the
		# translation of a singular form of a message, so dump
		# the contents of the singular array and output the
		# "msgstr" translation.  Strip all trailing empty strings
		# that have no effect on the output, and handle "\n"
		# pickiness between msgid and msgstr.
		#
		MSGSTR_RE = OBSOLETE_RE "msgstr"
		if ($0 ~ MSGSTR_RE KEYWORD_SEP) {
			if (s > 0) {
				print obsolete "msgid " singular[0]
				for (i = 1; i < s; i++)
					print obsolete singular[i]
			}
			if ($0 ~ OBSOLETE_RE_MATCH) obsolete = OBSOLETE
			sub(MSGSTR_RE SPACE, "")
			t = 0
			if ($0 ~ EMPTY) $0 = "\"\""
			$0 = strip_bad_ctrl_sequences($0)
			translation[t++] = $0
			while (result = getline) {
				if ($0 !~ MSG_CONTINUATION_RE) break
				sub(OBSOLETE_RE, "")
				$0 = strip_bad_ctrl_sequences($0)
				translation[t++] = $0
			}
			if (result < 0) break
			while ((t > 1) && (translation[t-1] ~ /^""$/)) t--
			if ((singular[s-1] ~ /\\n"$/) &&
			    (translation[t-1] !~ /\\n"$/)) {
				if (translation[t-1] !~ /""/)
					sub("\"$", "\\n\"", translation[t-1])
			}
			if (t > 0) {
				print obsolete "msgstr " translation[0]
				for (i = 1; i < t; i++)
					print obsolete translation[i]
			}
			continue
		}

		# If we see "msgstr[0]", then we are outputting the
		# translation of a singular form of a message, so dump
		# the contents of the singular array and output the
		# "msgstr[0]" translation.  Strip all trailing empty
		# strings that have no effect on the output, and handle
		# "\n" pickiness between msgid and msgstr.
		#
		MSGSTR0_RE = OBSOLETE_RE "msgstr[[]0[]]"
		if ($0 ~ MSGSTR0_RE KEYWORD_SEP) {
			if (s > 0) {
				print obsolete "msgid " singular[0]
				for (i = 1; i < s; i++)
					print obsolete singular[i]
			}
			if ($0 ~ OBSOLETE_RE_MATCH) obsolete = OBSOLETE
			sub(MSGSTR0_RE SPACE, "");
			t = 0
			if ($0 ~ EMPTY) $0 = "\"\""
			$0 = strip_bad_ctrl_sequences($0)
			translation[t++] = $0
			while (result = getline) {
				if ($0 !~ MSG_CONTINUATION_RE) break
				sub(OBSOLETE_RE, "")
				$0 = strip_bad_ctrl_sequences($0)
				translation[t++] = $0
			}
			if (result < 0) break
			while ((t > 1) && (translation[t-1] ~ /^""$/)) t--
			if ((singular[s-1] ~ /\\n"$/) &&
			    (translation[t-1] !~ /\\n"$/)) {
				if (translation[t-1] !~ /""/)
					sub("\"$", "\\n\"", translation[t-1])
			}
			if (t > 0) {
				print obsolete "msgstr " translation[0]
				for (i = 1; i < t; i++)
					print obsolete translation[i]
			}
			continue
		}

		# If we see "msgstr[1]", then we are outputting the
		# translation of a plural form of a message, so dump
		# the contents of the plural array and output the
		# "msgstr[1]" translation.  Strip all trailing empty
		# strings that have no effect on the output, and handle
		# "\n" pickiness between msgid and msgstr.
		#
		MSGSTR1_RE = OBSOLETE_RE "msgstr[[]1[]]"
		if ($0 ~ MSGSTR1_RE KEYWORD_SEP) {
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
				while (result = getline) {
					if ($0 !~ MSG_CONTINUATION_RE) break
				}
				if (result < 0) break
				s = 0; p = 0
				continue
			}

			if (p > 0) {
				print obsolete "msgid " plural[0]
				for (i = 1; i < p; i++)
					print obsolete plural[i]
			}
			if ($0 ~ OBSOLETE_RE_MATCH) obsolete = OBSOLETE
			sub(MSGSTR1_RE SPACE, "");
			t = 0
			if ($0 ~ EMPTY) $0 = "\"\""
			$0 = strip_bad_ctrl_sequences($0)
			translation[t++] = $0
			while (result = getline) {
				if ($0 !~ MSG_CONTINUATION_RE) break
				sub(OBSOLETE_RE, "")
				$0 = strip_bad_ctrl_sequences($0)
				translation[t++] = $0
			}
			if (result < 0) break
			while ((t > 1) && (translation[t-1] ~ /^""$/)) t--
			if ((plural[p-1] ~ /\\n"$/) &&
			    (translation[t-1] !~ /\\n"$/)) {
				if (translation[t-1] !~ /""/)
					sub("\"$", "\\n\"", translation[t-1])
			}
			if (t > 0) {
				print obsolete "msgstr " translation[0]
				for (i = 1; i < t; i++)
					print obsolete translation[i]
			}
			continue
		}

		# We drop all other "msgstr[N]" translations since the
		# old format only supported a single translation per
		# plural form.
		#
		MSGSTRN_RE = OBSOLETE_RE "msgstr[[][0-9]+[]]"
		if ($0 ~ MSGSTRN_RE KEYWORD_SEP) {
			while (result = getline) {
				if ($0 !~ MSG_CONTINUATION_RE) break
				print $0
			}
			if (result < 0) break
			continue
		}

		# Pass everything else verbatim.
		print $0
		result = getline
		if (result < 0) break
	}
}
' | $debug | $cmd
