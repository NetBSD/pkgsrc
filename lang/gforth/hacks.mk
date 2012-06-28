# $NetBSD: hacks.mk,v 1.1 2012/06/28 07:44:39 dholland Exp $

.include "../../mk/bsd.prefs.mk"

#
# A bug in the offending versions (listed below) in main.c of NetBSD's
# m4 causes the build to loop forever allocating memory, and thus
# exhaust swap. Note that these versions were never in a release, but
# their existence did span most of the 5.99.x period and early
# netbsd-6 prereleases. Therefore, updating the broken system binary
# is the best course of action. Note that because TOOLS_PATH.m4 does
# not get defined early enough it does not seem to be possible to set
# PKG_FAIL_REASON.
#

.if ${OPSYS} == "NetBSD"
pre-configure:
	@${ECHO} '=> Checking ${TOOLS_PATH.m4}'
	@set -e;							\
	m4_main_ver=`ident ${TOOLS_PATH.m4} |				\
			grep 'NetBSD: main.c' |				\
			awk '{print $$3}'`;				\
	case "$$m4_main_ver" in						\
		1.38|1.39]|1.40|1.41)					\
			${ECHO} "${TOOLS_PATH.m4} contains main.c"	\
				"$$m4_main_ver.";			\
			${ECHO} "Building this package using"		\
				"${TOOLS_PATH.m4} will run out of swap.";\
			${ECHO} "Please update ${TOOLS_PATH.m4} from CVS.";\
			exit 1;						\
		;;							\
	esac
.endif
