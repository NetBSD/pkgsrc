# $NetBSD: buildlink3.mk,v 1.9 2023/01/29 21:14:22 ryoon Exp $

BUILDLINK_TREE+=	quazip

.if !defined(QUAZIP_BUILDLINK3_MK)
QUAZIP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.quazip+=	quazip>=0.9
BUILDLINK_ABI_DEPENDS.quazip?=	quazip>=0.9nb8
BUILDLINK_PKGSRCDIR.quazip?=	../../archivers/quazip

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# QUAZIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-quazip
