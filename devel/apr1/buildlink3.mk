# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/12/08 23:29:53 xtraeme Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
APR_BUILDLINK3_MK:=	${APR_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	apr
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Napr}
BUILDLINK_PACKAGES+=	apr
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}apr

.if !empty(APR_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.apr+=	apr>=1.2.8
BUILDLINK_PKGSRCDIR.apr?=	../../devel/apr1

WRAPPER_REORDER_CMDS+=	reorder:l:aprutil-1:crypt

BUILDLINK_FILES.apr+=	bin/apr-config
BUILDLINK_FILES.apr+=	bin/apu-config
BUILDLINK_FILES.apr+=	lib/*.exp

.include "../../mk/bsd.prefs.mk"

.  if !defined(PKG_BUILD_OPTIONS.apr)
PKG_BUILD_OPTIONS.apr!=	cd ${BUILDLINK_PKGSRCDIR.apr} && \
			${MAKE} show-var ${MAKEFLAGS} VARNAME=PKG_OPTIONS
MAKEFLAGS+=	PKG_BUILD_OPTIONS.apr=${PKG_BUILD_OPTIONS.apr:Q}
.  endif
MAKEVARS+=	PKG_BUILD_OPTIONS.apr
.endif	# APR_BUILDLINK3_MK

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}

.if !empty(PKG_BUILD_OPTIONS.apr:Mdb4)
.  include "../../databases/db4/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.apr:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
