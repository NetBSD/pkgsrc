# $NetBSD: shlib-aout.awk,v 1.4 2018/08/22 20:48:37 maya Exp $
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
# This awk script is a filter that reads PLIST entries and strips out
# entries that match ELF library symlinks that aren't installed on a.out
# platforms.
#

BEGIN {
	LIBTOOL_EXPAND = ENVIRON["LIBTOOL_EXPAND"] ? ENVIRON["LIBTOOL_EXPAND"] : "/usr/pkgsrc/mk/plist/libtool-expand"
	LIBTOOLIZE_PLIST = ENVIRON["LIBTOOLIZE_PLIST"] ? ENVIRON["LIBTOOLIZE_PLIST"] : "yes"
	PREFIX = ENVIRON["PREFIX"] ? ENVIRON["PREFIX"] : "/usr/pkg"
	TEST = ENVIRON["TEST"] ? ENVIRON["TEST"] : "test"
	nentries = 0
}

###
### Stored special PLIST commands, e.g. @comment, @exec, etc., verbatim
### in the entries array.
###
/^@/ {
	entries[++nentries] = $0
	next
}

###
### Record all of the library names associated with a libtool archive
### in the "ltnames" array.  Also, record the libtool archive in the
### "entries" array.
###
(LIBTOOLIZE_PLIST ~ /[yY][eE][sS]/) && /.*\/[^\/]+\.la$/ {
	entries[++nentries] = $0
	cmd = TEST " -f " PREFIX "/" $0
	if (system(cmd) == 0) {
		cmd = "cd " PREFIX " && " LIBTOOL_EXPAND " " $0
		while (cmd | getline) {
			ltnames[$0] = $0
		}
		close(cmd)
	}
	next
}

###
### Record all library symlinks derived from a shared library name in the
### "symlinks" array.  Also, record the full shared library name in the
### "entries" array.
###
/.*\/lib[^\/]+\.so(\.[0-9]+)*$/ {
	entries[++nentries] = $0
	while (sub("\\.[0-9]+$", "")) {
		symlinks[$0] = $0
	}
	if (sub("-[^-]+\\.so$", ".so")) {
		symlinks[$0] = $0
	}
	next
}

###
### All other entries are stored verbatim in the entries array.
###
{
	entries[++nentries] = $0
}

###
### Print out the PLIST entries to standard output.
###
END {
	# Drop valid library names associated with a libtool archive from
	# the list of library symlinks that will be removed from the PLIST.
	#
	for (j in symlinks) {
		for (k in ltnames) {
			if (symlinks[j] == ltnames[k]) {
				delete symlinks[j]
				break
			}
		}
	}

	# Remove PLIST entries which match a library symlink.
	for (i in entries) {
		for (j in symlinks) {
			if (entries[i] == symlinks[j]) {
				delete entries[i]
				break
			}
		}
	}

	# Output the PLIST entries in order.
	for (i = 1; i <= nentries; i++) {
		if (entries[i]) {
			print entries[i]
		}
	}
}
