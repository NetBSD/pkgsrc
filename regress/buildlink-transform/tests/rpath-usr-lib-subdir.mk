# $NetBSD: rpath-usr-lib-subdir.mk,v 1.1.1.1 2004/08/27 21:34:58 jlam Exp $

.PHONY: rpath-usr-lib-subdir
do-regress: rpath-usr-lib-subdir
rpath-usr-lib-subdir:
	@test="${COMPILER_RPATH_FLAG}/usr/lib/i18n";			\
	expected="${COMPILER_RPATH_FLAG}/usr/lib/i18n";			\
	${TEST_RESULT}
