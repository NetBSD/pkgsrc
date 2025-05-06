# $NetBSD: buildlink3.mk,v 1.1 2025/05/06 13:00:25 wiz Exp $

BUILDLINK_TREE+=	quazip1

.if !defined(QUAZIP1_BUILDLINK3_MK)
QUAZIP1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.quazip1+=	quazip1>=1.5
BUILDLINK_PKGSRCDIR.quazip1?=	../../archivers/quazip1

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# QUAZIP1_BUILDLINK3_MK

BUILDLINK_TREE+=	-quazip1
