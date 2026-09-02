# $NetBSD: buildlink3.mk,v 1.35 2026/09/02 19:03:25 wiz Exp $

BUILDLINK_TREE+=	attica

.if !defined(ATTICA_BUILDLINK3_MK)
ATTICA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.attica+=	attica>=0.1.2
BUILDLINK_ABI_DEPENDS.attica+=	attica>=0.4.2nb14
BUILDLINK_PKGSRCDIR.attica?=	../../misc/attica

.include "../../x11/qt4-libs/buildlink3.mk"
.endif	# ATTICA_BUILDLINK3_MK

BUILDLINK_TREE+=	-attica
