# $NetBSD: buildlink3.mk,v 1.12 2004/11/26 19:31:33 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
APR_BUILDLINK3_MK:=	${APR_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	apr
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Napr}
BUILDLINK_PACKAGES+=	apr

.if !empty(APR_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.apr+=	apr>=0.9.5.2.0.51nb1
BUILDLINK_RECOMMENDED.apr+=	apr>=0.9.5.2.0.52nb1
BUILDLINK_PKGSRCDIR.apr?=	../../devel/apr

BUILDLINK_FILES.apr+=	bin/apr-config
BUILDLINK_FILES.apr+=	bin/apu-config
BUILDLINK_FILES.apr+=	lib/*.exp
.endif	# APR_BUILDLINK3_MK

PKG_OPTIONS.apr?=	${PKG_DEFAULT_OPTIONS}

.if !empty(PKG_OPTIONS.apr:Mdb4)
.  include "../../databases/db4/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS.apr:Mldap)
.  include "../../databases/openldap/buildlink3.mk"
.endif

.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
