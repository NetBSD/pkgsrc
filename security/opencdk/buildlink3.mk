# $NetBSD: buildlink3.mk,v 1.4 2004/04/02 15:57:58 agc Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OPENCDK_BUILDLINK3_MK:=	${OPENCDK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	opencdk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nopencdk}
BUILDLINK_PACKAGES+=	opencdk

.if !empty(OPENCDK_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.opencdk+=	opencdk>=0.5.4
BUILDLINK_PKGSRCDIR.opencdk?=	../../security/opencdk
.endif	# OPENCDK_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
