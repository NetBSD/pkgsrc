# $NetBSD: buildlink3.mk,v 1.15 2023/01/29 21:14:59 ryoon Exp $

BUILDLINK_TREE+=	libfm

.if !defined(LIBFM_BUILDLINK3_MK)
LIBFM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfm+=	libfm>=1.2.3
BUILDLINK_ABI_DEPENDS.libfm?=	libfm>=1.3.2nb4
BUILDLINK_PKGSRCDIR.libfm?=	../../sysutils/libfm

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../sysutils/menu-cache/buildlink3.mk"
.endif	# LIBFM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfm
