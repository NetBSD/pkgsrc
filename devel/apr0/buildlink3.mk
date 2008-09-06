# $NetBSD: buildlink3.mk,v 1.9 2008/09/06 20:54:32 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
APR_BUILDLINK3_MK:=	${APR_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	apr
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Napr}
BUILDLINK_PACKAGES+=	apr
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}apr

.if !empty(APR_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.apr+=	apr-0.9.* apr>=0.9.5.2.0.51nb1
BUILDLINK_ABI_DEPENDS.apr+=	apr>=0.9.17.2.0.63nb1
BUILDLINK_PKGSRCDIR.apr?=	../../devel/apr0
BUILDLINK_INCDIRS.apr?=		include/apr-0

WRAPPER_REORDER_CMDS+=	reorder:l:aprutil-0:crypt

BUILDLINK_FILES.apr+=	bin/apr-config
BUILDLINK_FILES.apr+=	bin/apu-config
BUILDLINK_FILES.apr+=	lib/*.exp

.endif	# APR_BUILDLINK3_MK

.include "../../mk/bsd.fast.prefs.mk"

pkgbase := apr
.include "../../mk/pkg-build-options.mk"

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
