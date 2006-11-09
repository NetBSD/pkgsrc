# $NetBSD: check-headers.mk,v 1.2 2006/11/09 14:41:18 rillig Exp $
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
# CHECK_HEADERS_SKIP:
#	A list of filename patterns that should be skipped for this test.
#

.if defined(PKG_DEVELOPER)
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
	env	PKGSRCDIR=${PKGSRCDIR:Q}				\
		SKIP_FILTER=${CHECK_HEADERS_SKIP:@p@${p}) skip=yes;;@:Q} \
		sh ${PKGSRCDIR}/mk/check/check-headers.sh
