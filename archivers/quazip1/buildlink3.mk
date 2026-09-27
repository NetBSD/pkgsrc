# $NetBSD: buildlink3.mk,v 1.6 2026/09/27 11:34:46 tnn Exp $

BUILDLINK_TREE+=	quazip1

.if !defined(QUAZIP1_BUILDLINK3_MK)
QUAZIP1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.quazip1+=	quazip1>=1.7
BUILDLINK_ABI_DEPENDS.quazip1?=	quazip1>=1.7.2nb1
BUILDLINK_PKGSRCDIR.quazip1?=	../../archivers/quazip1

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# QUAZIP1_BUILDLINK3_MK

BUILDLINK_TREE+=	-quazip1
