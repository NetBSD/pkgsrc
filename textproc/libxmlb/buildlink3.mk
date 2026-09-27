# $NetBSD: buildlink3.mk,v 1.4 2026/09/27 11:38:52 tnn Exp $

BUILDLINK_TREE+=	libxmlb

.if !defined(LIBXMLB_BUILDLINK3_MK)
LIBXMLB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libxmlb+=	libxmlb>=0.3.14
BUILDLINK_ABI_DEPENDS.libxmlb?=	libxmlb>=0.3.29nb2
BUILDLINK_PKGSRCDIR.libxmlb?=	../../textproc/libxmlb

.include "../../devel/glib2/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.endif	# LIBXMLB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libxmlb
