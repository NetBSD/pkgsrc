# $NetBSD: depsrc-nopath.mk,v 1.1 2024/07/15 09:10:14 jperkin Exp $
#
# Tests for the special source .NOPATH in dependency declarations.

.if !target(test-*)
_!=	rm -rf depsrc-nopath.dir
_!=	mkdir depsrc-nopath.dir
_!=	touch depsrc-nopath.dir/regular.file
_!=	touch depsrc-nopath.dir/nopath.file
.endif

all:
	@${MAKE} -f ${MAKEFILE} test-regular
	@${MAKE} -f ${MAKEFILE} test-nopath || echo "should have failed"
	@rm -rf depsrc-nopath.dir

.PATH: depsrc-nopath.dir

test-regular: regular.file
	: Making ${.TARGET} from ${.ALLSRC}
test-nopath: nopath.file
	: Making ${.TARGET} from ${.ALLSRC}

nopath.file: .NOPATH

# expect: : Making test-regular from depsrc-nopath.dir/regular.file
# expect: : Making test-nopath from nopath.file
