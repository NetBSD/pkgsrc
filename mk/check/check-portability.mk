# $NetBSD: check-portability.mk,v 1.13 2020/03/13 08:04:08 rillig Exp $
#
# This file checks that the extracted shell programs don't contain
# bashisms and other constructs that only work on some platforms.
#
# User-settable variables:
#
# CHECK_PORTABILITY
#	Whether to enable the portability checks.
#
#	Default value: yes for PKG_DEVELOPERs, no otherwise.
#
# Package-settable variables:
#
# CHECK_PORTABILITY_SKIP
#	The shell patterns that should not be checked.
#	Note that a * in a pattern also matches a slash in a pathname.
#
#	Default value: ${REPLACE_BASH}
#	Examples: debian/* test/* *.bash

_VARGROUPS+=			check-portability
_USER_VARS.check-portability=	CHECK_PORTABILITY
_PKG_VARS.check-portability=	CHECK_PORTABILITY_SKIP

.if ${PKG_DEVELOPER:Uno} != no
CHECK_PORTABILITY?=		yes
.endif
CHECK_PORTABILITY?=		no
CHECK_PORTABILITY_SKIP?=	${REPLACE_BASH}

.if ${CHECK_PORTABILITY:tl} == yes && ${CHECK_PORTABILITY_SKIP} != "*"
TOOL_DEPENDS+=	check-portability>=19.4.1:../../pkgtools/check-portability
pre-configure-checks-hook: _check-portability
.endif

.PHONY: _check-portability
_check-portability:
	@${STEP_MSG} "Checking for portability problems in extracted files"
	${RUN}								\
	[ -d ${WRKSRC}/. ] || exit 0;					\
	cd ${WRKSRC};							\
	env	SKIP_FILTER=${CHECK_PORTABILITY_SKIP:@p@${p}) skip=yes;;@:Q} \
		PREFIX=${PREFIX}					\
		sh ${PKGSRCDIR}/mk/check/check-portability.sh
