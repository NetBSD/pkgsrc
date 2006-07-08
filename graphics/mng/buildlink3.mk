# $NetBSD: buildlink3.mk,v 1.10 2006/07/08 23:10:52 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
MNG_BUILDLINK3_MK:=	${MNG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	mng
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmng}
BUILDLINK_PACKAGES+=	mng
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}mng

.if !empty(MNG_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.mng+=		mng>=1.0.0
BUILDLINK_ABI_DEPENDS.mng+=	mng>=1.0.9nb1
BUILDLINK_PKGSRCDIR.mng?=	../../graphics/mng
.endif	# MNG_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
