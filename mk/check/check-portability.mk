# $NetBSD: check-portability.mk,v 1.22 2024/10/11 10:13:13 jperkin Exp $
#
# This file checks that the extracted shell programs don't contain
# bashisms or other constructs that only work on some platforms.
#
# User-settable variables:
#
# CHECK_PORTABILITY
#	Whether to enable the portability checks.
#
#	Default value: yes for PKG_DEVELOPERs, no otherwise.
#
# CHECK_PORTABILITY_EXPERIMENTAL
#	Enable additional experimental portability checks. New checks
#	may be added without further notice, so expect some packages
#	that previously succeeded to suddenly fail to build.
#
#	Default value: no
#
# Package-settable variables:
#
# CHECK_PORTABILITY_SKIP
#	The filename patterns that should not be checked.
#	Note that a * in a pattern also matches a slash in a pathname.
#
#	Default value: ${REPLACE_BASH}
#	Examples: debian/* test/* *.bash

_VARGROUPS+=			check-portability
_USER_VARS.check-portability=	CHECK_PORTABILITY \
				CHECK_PORTABILITY_EXPERIMENTAL
_PKG_VARS.check-portability=	CHECK_PORTABILITY_SKIP REPLACE_BASH
_USE_VARS.check-portability=	PKG_DEVELOPER
_LISTED_VARS.check-portability=	REPLACE_BASH

.if ${PKG_DEVELOPER:Uno} != "no"
CHECK_PORTABILITY?=		yes
.endif
CHECK_PORTABILITY?=		no
CHECK_PORTABILITY_SKIP?=	${REPLACE_BASH}

.if ${CHECK_PORTABILITY:tl} == yes && ${CHECK_PORTABILITY_SKIP} != "*"
pre-configure-checks-hook: _check-portability
.endif

.if !empty(TOOLS_PLATFORM.mktool)
CHECK_PORTABILITY_PROGRAM=	${TOOLS_PLATFORM.mktool} check-portability
.else
CHECK_PORTABILITY_PROGRAM=	${SH} ${PKGSRCDIR}/mk/check/check-portability.sh
.endif

.PHONY: _check-portability
_check-portability:
	${RUN}								\
	${STEP_MSG} "Checking for portability problems in extracted files"; \
	[ -d ${WRKSRC}/. ] || exit 0;					\
	cd ${WRKSRC};							\
	${SETENV}							\
		SKIP_FILTER=${CHECK_PORTABILITY_SKIP:@p@${p}) skip=yes;;@:Q} \
		PREFIX=${PREFIX}					\
		PATCHDIR=${PATCHDIR}					\
		CHECK_PORTABILITY_EXPERIMENTAL=${CHECK_PORTABILITY_EXPERIMENTAL:Uno} \
		CHECK_PORTABILITY_SKIP=${CHECK_PORTABILITY_SKIP:Q}	\
		LC_ALL=C \
		${CHECK_PORTABILITY_PROGRAM}
