# $NetBSD: check-portability.mk,v 1.9 2019/10/06 13:38:22 rillig Exp $
#
# This file contains some checks that are applied to the configure
# scripts to check for certain constructs that are known to cause
# problems on some platforms. The detailed checks are in
# check-portability.sh.
#
# User-settable variables:
#
# CHECK_PORTABILITY
#	Whether to enable some portability checks for the configure
#	scripts before they are run.
#
#	Default value: yes for PKG_DEVELOPERs, no otherwise.
#
# Package-settable variables:
#
# CHECK_PORTABILITY_SKIP
#	The list of files that should be skipped in the portability
#	check.
#
#	Default value: empty.
#	Example: debian/*

_VARGROUPS+=			check-portability
_USER_VARS.check-portability=	CHECK_PORTABILITY
_PKG_VARS.check-portability=	CHECK_PORTABILITY_SKIP

.if ${PKG_DEVELOPER:Uno} != "no"
CHECK_PORTABILITY?=		yes
.endif
CHECK_PORTABILITY?=		no
.if defined(SKIP_PORTABILITY_CHECK)
PKG_FAIL_REASON+=		"[check-portability.mk] SKIP_PORTABILITY_CHECK is obsolete."
.endif
CHECK_PORTABILITY_SKIP?=	# none

.if ${CHECK_PORTABILITY:M[Yy][Ee][Ss]} != ""
pre-configure-checks-hook: _check-portability
.endif
.PHONY: _check-portability
_check-portability:
	@${STEP_MSG} "Checking for portability problems in extracted files"
	${RUN}								\
	[ -d ${WRKSRC}/. ] || exit 0;					\
	cd ${WRKSRC};							\
	env	SKIP_FILTER=${CHECK_PORTABILITY_SKIP:@p@${p}) skip=yes;;@:Q} \
		sh ${PKGSRCDIR}/mk/check/check-portability.sh
