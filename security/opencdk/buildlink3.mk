# $NetBSD: buildlink3.mk,v 1.1 2004/02/10 00:20:29 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OPENCDK_BUILDLINK3_MK:=	${OPENCDK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	opencdk
.endif

.if !empty(OPENCDK_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		opencdk
BUILDLINK_DEPENDS.opencdk+=	opencdk>=0.5.3
BUILDLINK_PKGSRCDIR.opencdk?=	../../security/opencdk

.  include "../../devel/zlib/buildlink3.mk"
.  include "../../security/libgcrypt/buildlink3.mk"
.endif # OPENCDK_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
