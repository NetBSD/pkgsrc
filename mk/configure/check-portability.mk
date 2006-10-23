# $NetBSD: check-portability.mk,v 1.7 2006/10/23 16:07:12 rillig Exp $
#
# This file contains some checks that are applied to the configure
# scripts to check for certain constructs that are known to cause
# problems on some platforms.
#
# The following variables may be set by the pkgsrc user in mk.conf:
#
# CHECK_PORTABILITY: YesNo
#	Whether to enable some portability checks for the configure
#	scripts before they are run.
#
#	Default value: yes for PKG_DEVELOPERs, no otherwise.
#
# The following variables may be set by the package:
#
# SKIP_PORTABILITY_CHECK: YesNo
#	Whether the above checks should be skipped for the current
#	package.
#
#	Default value: no
#
# CHECK_PORTABILITY_SKIP: List of Pathmask
#	The list of files that should be skipped in the portability
#	check.
#
#	Default value: empty.
#

.if defined(PKG_DEVELOPER) && !empty(PKG_DEVELOPER:M[Yy][Ee][Ss])
CHECK_PORTABILITY?=		yes
.endif
CHECK_PORTABILITY?=		no
SKIP_PORTABILITY_CHECK?=	no
CHECK_PORTABILITY_SKIP?=	# none

.if ${CHECK_PORTABILITY:M[Yy][Ee][Ss]} != "" && \
    ${SKIP_PORTABILITY_CHECK:M[Yy][Ee][Ss]} == ""
do-configure-pre-hook: _configure-check-for-test
.endif
.PHONY: _configure-check-for-test
_configure-check-for-test:
	@${STEP_MSG} "Checking for portability problems in extracted files"
	${_PKG_SILENT}${_PKG_DEBUG}					\
	[ -d ${WRKSRC}/. ] || exit 0;					\
	cd ${WRKSRC}							\
	&& env SKIP_FILTER=${CHECK_PORTABILITY_SKIP:@p@${p}) continue;;@:Q} \
		sh ${PKGSRCDIR}/mk/configure/check-portability.sh
