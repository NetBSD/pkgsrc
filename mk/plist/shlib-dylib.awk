# $NetBSD: shlib-dylib.awk,v 1.5 2018/08/22 20:48:37 maya Exp $
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
# This awk script is a filter that reads PLIST entries and transforms
# and expands entries that match ELF library into the appropriate Mach-O
# dylib names.
#

BEGIN {
	LIBTOOL_EXPAND = ENVIRON["LIBTOOL_EXPAND"] ? ENVIRON["LIBTOOL_EXPAND"] : "/usr/pkgsrc/mk/plist/libtool-expand"
	LIBTOOLIZE_PLIST = ENVIRON["LIBTOOLIZE_PLIST"] ? ENVIRON["LIBTOOLIZE_PLIST"] : "yes"
	PREFIX = ENVIRON["PREFIX"] ? ENVIRON["PREFIX"] : "/usr/pkg"
	TEST = ENVIRON["TEST"] ? ENVIRON["TEST"] : "test"
	nentries = 0
}

###
### add_dylib(lib) adds the named "lib" to the PLIST entries list and
###	to the dylibs list if we haven't already seen it.
###
function add_dylib(lib) {
	if (dylibs[lib] == "") {
		dylibs[lib] = lib
		entries[++nentries] = lib
	}
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
### Convert each ELF shlib entry into a dylib entry.  Also, record all
### dylib names that can be derived from this entry as dylibs.
###
/.*\/lib[^\/]+\.so(\.[0-9]+)+$/ {
	cmd = TEST " -f " PREFIX "/" $0
	if (system(cmd) == 0) {
		entries[++nentries] = $0
	}
	lib = $0; sub("\\.so\\.", ".", lib); sub("\\.so$", "", lib)
	lib = lib ".dylib"
	add_dylib(lib)
	while (sub("\\.[0-9]+$", "")) {
		lib = $0; sub("\\.so\\.", ".", lib); sub("\\.so$", "", lib)
		lib = lib ".dylib"
		add_dylib(lib)
	}
	if (sub("\\.so$", "")) {
		lib = $0 ".dylib"
		add_dylib(lib)
	}
	if (sub("-([0-9.]+)$", "")) {
		lib = $0 ".dylib"
		add_dylib(lib)
	}
	next
}

###
### If the ".so" file actually exists, then it's a dynamically loadable
### module, so the entry should stay.  Convert it into a dylib name as
### well and record it as a dylib.
###
/.*\/lib[^\/]+\.so$/ {
	cmd = TEST " -f " PREFIX "/" $0
	if (system(cmd) == 0) {
		entries[++nentries] = $0
	}
	lib = $0; sub("\\.so$", "", lib)
	lib = lib ".dylib"
	add_dylib(lib)
	if (sub("-([0-9.]+)$", "")) {
		lib = $0 ".dylib"
		add_dylib(lib)
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
	# the list of dylibs that will be removed from the PLIST.
	#
	for (j in dylibs) {
		for (k in ltnames) {
			if (dylibs[j] == ltnames[k]) {
				delete dylibs[j]
				break
			}
		}
	}

	# Remove dylib entries that *do* exist on the filesystem from the
	# list of dylibs that will be removed from the PLIST.
	#
	for (j in dylibs) {
		cmd = TEST " -f " PREFIX "/" dylibs[j]
		if (system(cmd) == 0) {
			delete dylibs[j]
		}
	}

	# Remove PLIST entries that match a non-existent dylib.
	for (i in entries) {
		for (j in dylibs) {
			if (entries[i] == dylibs[j]) {
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
