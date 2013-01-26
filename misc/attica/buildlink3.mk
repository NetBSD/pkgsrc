# $NetBSD: buildlink3.mk,v 1.16 2013/01/26 21:36:36 adam Exp $

BUILDLINK_TREE+=	attica

.if !defined(ATTICA_BUILDLINK3_MK)
ATTICA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.attica+=	attica>=0.1.2
BUILDLINK_ABI_DEPENDS.attica+=	attica>=0.2.0nb12
BUILDLINK_PKGSRCDIR.attica?=	../../misc/attica

.include "../../x11/qt4-libs/buildlink3.mk"
.endif	# ATTICA_BUILDLINK3_MK

BUILDLINK_TREE+=	-attica
