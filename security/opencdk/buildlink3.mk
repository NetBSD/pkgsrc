# $NetBSD: buildlink3.mk,v 1.3 2004/03/18 09:12:14 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OPENCDK_BUILDLINK3_MK:=	${OPENCDK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	opencdk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nopencdk}
BUILDLINK_PACKAGES+=	opencdk

.if !empty(OPENCDK_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.opencdk+=	opencdk>=0.5.3
BUILDLINK_PKGSRCDIR.opencdk?=	../../security/opencdk
.endif	# OPENCDK_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
