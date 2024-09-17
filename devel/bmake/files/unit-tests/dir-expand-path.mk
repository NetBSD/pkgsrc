# $NetBSD: dir-expand-path.mk,v 1.2 2024/09/17 11:52:31 jperkin Exp $
#
# Tests for filename expansion in the search path.

_!=	rm -rf dir-expand-path.dir.*
_!=	mkdir dir-expand-path.dir.1
_!=	mkdir dir-expand-path.dir.2
_!=	touch dir-expand-path.dir.1/file1.src
_!=	touch dir-expand-path.dir.1/file2.src
_!=	touch dir-expand-path.dir.2/file3.src

.PATH: dir-expand-path.dir.1
.PATH: dir-expand-path.dir.2

all: *.src
	@printf '%s\n' ${.ALLSRC:O}

.END:
	@rm -rf dir-expand-path.dir.*
