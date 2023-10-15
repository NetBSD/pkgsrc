# $NetBSD: buildlink3.mk,v 1.1 2023/10/15 07:50:09 wiz Exp $

BUILDLINK_TREE+=	libxmlb

.if !defined(LIBXMLB_BUILDLINK3_MK)
LIBXMLB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxmlb+=	libxmlb>=0.3.14
BUILDLINK_PKGSRCDIR.libxmlb?=	../../textproc/libxmlb

.include "../../devel/glib2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.endif	# LIBXMLB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxmlb
