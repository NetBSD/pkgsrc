# $NetBSD: buildlink3.mk,v 1.5 2026/09/29 06:07:51 wiz Exp $

BUILDLINK_TREE+=	libxmlb

.if !defined(LIBXMLB_BUILDLINK3_MK)
LIBXMLB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxmlb+=	libxmlb>=0.3.14
BUILDLINK_ABI_DEPENDS.libxmlb?=	libxmlb>=0.3.29nb3
BUILDLINK_PKGSRCDIR.libxmlb?=	../../textproc/libxmlb

.include "../../devel/glib2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.endif	# LIBXMLB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxmlb
