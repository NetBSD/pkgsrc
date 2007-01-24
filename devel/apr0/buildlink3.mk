# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/01/24 19:31:24 epg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
APR_BUILDLINK3_MK:=	${APR_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	apr
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Napr}
BUILDLINK_PACKAGES+=	apr
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}apr

.if !empty(APR_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.apr+=	apr>=0.9.5.2.0.51nb1
BUILDLINK_ABI_DEPENDS.apr+=	apr>=0.9.7.2.0.55nb2
BUILDLINK_PKGSRCDIR.apr?=	../../devel/apr0

WRAPPER_REORDER_CMDS+=	reorder:l:aprutil-0:crypt

BUILDLINK_FILES.apr+=	bin/apr-config
BUILDLINK_FILES.apr+=	bin/apu-config
BUILDLINK_FILES.apr+=	lib/*.exp

.include "../../mk/bsd.fast.prefs.mk"

.  if !defined(PKG_BUILD_OPTIONS.apr)
PKG_BUILD_OPTIONS.apr!=	cd ${BUILDLINK_PKGSRCDIR.apr} && \
			${MAKE} show-var ${MAKEFLAGS} VARNAME=PKG_OPTIONS
MAKEFLAGS+=	PKG_BUILD_OPTIONS.apr=${PKG_BUILD_OPTIONS.apr:Q}
.  endif
MAKEVARS+=	PKG_BUILD_OPTIONS.apr
.endif	# APR_BUILDLINK3_MK

.if !empty(PKG_BUILD_OPTIONS.apr:Mdb4)
.  include "../../databases/db4/buildlink3.mk"
.endif

.if !empty(PKG_BUILD_OPTIONS.apr:Mldap)
.  include "../../databases/openldap-client/buildlink3.mk"
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
