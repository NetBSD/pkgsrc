# $NetBSD: buildlink3.mk,v 1.2.4.1 2004/07/14 12:39:00 agc Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
APR_BUILDLINK3_MK:=	${APR_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	apr
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Napr}
BUILDLINK_PACKAGES+=	apr

.if !empty(APR_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.apr+=	apr>=0.9.5.2.0.50
BUILDLINK_PKGSRCDIR.apr?=	../../devel/apr

BUILDLINK_FILES.apr+=	bin/apr-config
BUILDLINK_FILES.apr+=	bin/apu-config
BUILDLINK_FILES.apr+=	lib/*.exp
.endif	# APR_BUILDLINK3_MK

.if !empty(APR_USE_DB4:M[yY][eE][sS])
.  include "../../databases/db4/buildlink3.mk"
.endif
.include "../../textproc/expat/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
