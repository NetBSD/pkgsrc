# $NetBSD: buildlink3.mk,v 1.4 2004/03/18 09:12:12 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
MNG_BUILDLINK3_MK:=	${MNG_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	mng
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nmng}
BUILDLINK_PACKAGES+=	mng

.if !empty(MNG_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.mng+=		mng>=1.0.0
BUILDLINK_PKGSRCDIR.mng?=	../../graphics/mng
.endif	# MNG_BUILDLINK3_MK

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
