# $NetBSD: check-headers.mk,v 1.6 2010/08/24 19:08:29 bad Exp $
#
# This file checks the C and C++ header files for possible problems.
#
# User-settable variables:
#
# CHECK_HEADERS
#	Whether the header files should be checked.
#
#	Default value: "yes" for PKG_DEVELOPERs, "no" otherwise.
#
# Package-settable-variables:
#
# CHECK_HEADERS_SKIP
#	A list of filename patterns that should be skipped for this test.
#

_VARGROUPS+=			check-headers
_USER_VARS.check-headers=	CHECK_HEADERS
_PKG_VARS.check-headers=	CHECK_HEADERS_SKIP

.if defined(PKG_DEVELOPER) && ${PKG_DEVELOPER} != "no"
# still experimental
#CHECK_HEADERS?=		yes
.endif
CHECK_HEADERS?=		no
CHECK_HEADERS_SKIP?=	# none

.if !empty(CHECK_HEADERS:M[Yy][Ee][Ss])
pre-build-checks-hook: _check-headers
.endif

.PHONY: _check-headers
_check-headers:
	@${STEP_MSG} "Checking for possible problems in header files"
	${RUN}								\
	[ -d ${WRKSRC}/. ] || exit 0;					\
	cd ${WRKSRC};							\
	env	SKIP_FILTER=${CHECK_HEADERS_SKIP:@p@${p}) skip=yes;;@:Q} \
		sh ${PKGSRCDIR}/mk/check/check-headers.sh
