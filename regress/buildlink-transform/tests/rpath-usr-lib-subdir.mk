# $NetBSD: rpath-usr-lib-subdir.mk,v 1.2 2004/08/30 05:03:32 jlam Exp $

.PHONY: rpath-usr-lib-subdir
do-regress: rpath-usr-lib-subdir
rpath-usr-lib-subdir:
	@test="${COMPILER_RPATH_FLAG}/usr/lib/i18n";			\
	case "${_USE_RPATH}" in						\
	[yY][eE][sS])							\
		expected="${COMPILER_RPATH_FLAG}/usr/lib/i18n";		\
		;;							\
	*)								\
		expected="";						\
		;;							\
	esac;								\
	${TEST_RESULT}
