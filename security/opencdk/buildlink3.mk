# $NetBSD: buildlink3.mk,v 1.11 2006/07/08 23:11:08 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OPENCDK_BUILDLINK3_MK:=	${OPENCDK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	opencdk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nopencdk}
BUILDLINK_PACKAGES+=	opencdk
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}opencdk

.if !empty(OPENCDK_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.opencdk+=	opencdk>=0.5.4nb1
BUILDLINK_ABI_DEPENDS.opencdk+=	opencdk>=0.5.8nb1
BUILDLINK_PKGSRCDIR.opencdk?=	../../security/opencdk
.endif	# OPENCDK_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
