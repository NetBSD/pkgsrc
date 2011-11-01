# $NetBSD: buildlink3.mk,v 1.7 2011/11/01 06:02:03 sbd Exp $

BUILDLINK_TREE+=	attica

.if !defined(ATTICA_BUILDLINK3_MK)
ATTICA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.attica+=	attica>=0.1.2
BUILDLINK_ABI_DEPENDS.attica?=	attica>=0.2.0nb4
BUILDLINK_PKGSRCDIR.attica?=	../../misc/attica

.include "../../x11/qt4-libs/buildlink3.mk"
.endif	# ATTICA_BUILDLINK3_MK

BUILDLINK_TREE+=	-attica
