# $NetBSD: buildlink3.mk,v 1.14 2023/11/12 13:20:32 wiz Exp $

BUILDLINK_TREE+=	quazip

.if !defined(QUAZIP_BUILDLINK3_MK)
QUAZIP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.quazip+=	quazip>=0.9
BUILDLINK_ABI_DEPENDS.quazip?=	quazip>=0.9nb14
BUILDLINK_PKGSRCDIR.quazip?=	../../archivers/quazip

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# QUAZIP_BUILDLINK3_MK

BUILDLINK_TREE+=	-quazip
