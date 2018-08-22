# $NetBSD: shlib-pe.awk,v 1.5 2018/08/22 20:48:37 maya Exp $
#
# Copyright (c) 2006,2013 The NetBSD Foundation, Inc.
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
# and expands entries that match ELF library into the appropriate Portable
# Executable format, PE on Cygwin dll names.
#

BEGIN {
	LIBTOOL_EXPAND = ENVIRON["LIBTOOL_EXPAND"] ? ENVIRON["LIBTOOL_EXPAND"] : "/usr/pkgsrc/mk/plist/libtool-expand"
	LIBTOOLIZE_PLIST = ENVIRON["LIBTOOLIZE_PLIST"] ? ENVIRON["LIBTOOLIZE_PLIST"] : "yes"
	PREFIX = ENVIRON["PREFIX"] ? ENVIRON["PREFIX"] : "/usr/pkg"
	TEST = ENVIRON["TEST"] ? ENVIRON["TEST"] : "test"
	nentries = 0
}

###
### add_dll(lib) adds the named "lib" to the PLIST entries list and
### to the dlls list if we haven't already seen it.
### dll may be in "bin" or its name may be cygXXX.dll instead of libXXX.dll.
###
function add_dll(lib) {
	if (dlls[lib] == "") {
		dlls[lib] = lib
		entries[++nentries] = lib
		if (sub("^lib/lib", "bin/lib", lib)) {
			add_dll(lib)
			sub("^bin/lib", "bin/cyg", lib)
			add_dll(lib)
		}
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
### Convert each ELF shlib entry into a dll entry.  Also, record all
### dll names that can be derived from this entry as dlls.
###
/.*\/lib[^\/]+\.so(\.[0-9]+)+$/ {
	lib = $0; sub("\\.so\\.", ".", lib); sub("\\.so$", "", lib)
	lib = lib ".dll"
	add_dll(lib)
	sub("\\.", "-", lib)
	add_dll(lib)
	while (sub("\\.[0-9]+$", "")) {
		lib = $0; sub("\\.so\\.", ".", lib); sub("\\.so$", "", lib)
		lib = lib ".dll"
		add_dll(lib)
		sub("\\.", "-", lib)
		add_dll(lib)
	}
	if (sub("\\.so$", "")) {
		lib = $0 ".dll"
		add_dll(lib)
	}
	if (sub("-([0-9.]+)$", "")) {
		lib = $0 ".dll"
		add_dll(lib)
	}
	next
}

###
### If the ".so" file actually exists, then it's a dynamically loadable
### module, so the entry should stay.  Convert it into a dll name as
### well and record it as a dll.
###
/.*\/[^\/]+\.so$/ {
	cmd = TEST " -f " PREFIX "/" $0
	if (system(cmd) == 0) {
		entries[++nentries] = $0
	}
	lib = $0; sub("\\.so$", "", lib)
	lib = lib ".dll"
	add_dll(lib)
	if (sub("-([0-9.]+)$", "")) {
		lib = $0 ".dll"
		add_dll(lib)
	}
	next
}

###
### If the ".a" file actually exists, then it's a library archive,
### so the entry should stay.  Convert it into a DLL import library name as
### well and record it as a DLL.
###
/.*\/lib[^\/]+\.a$/ {
	cmd = TEST " -f " PREFIX "/" $0
	if (system(cmd) == 0) {
		entries[++nentries] = $0
	}
	lib = $0; sub("\\.a$", ".dll.a", lib)
	cmd = TEST " -f " PREFIX "/" lib
	if (system(cmd) == 0) {
		entries[++nentries] = lib
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
	# the list of dlls that will be removed from the PLIST.
	#
	for (j in dlls) {
		for (k in ltnames) {
			if (dlls[j] == ltnames[k]) {
				delete dlls[j]
				break
			}
		}
	}

	# Remove dll entries that *do* exist on the filesystem from the
	# list of dlls that will be removed from the PLIST.
	#
	for (j in dlls) {
		cmd = TEST " -f " PREFIX "/" dlls[j]
		if (system(cmd) == 0) {
			delete dlls[j]
		}
	}

	# Remove PLIST entries that match a non-existent dll.
	for (i in entries) {
		for (j in dlls) {
			if (entries[i] == dlls[j]) {
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
