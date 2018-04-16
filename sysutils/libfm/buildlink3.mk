# $NetBSD: buildlink3.mk,v 1.6 2018/04/16 14:33:56 wiz Exp $

BUILDLINK_TREE+=	libfm

.if !defined(LIBFM_BUILDLINK3_MK)
LIBFM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfm+=	libfm>=1.2.3
BUILDLINK_ABI_DEPENDS.libfm?=	libfm>=1.2.4nb5
BUILDLINK_PKGSRCDIR.libfm?=	../../sysutils/libfm

.include "../../x11/gtk2/buildlink3.mk"
.include "../../sysutils/menu-cache/buildlink3.mk"
.endif	# LIBFM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfm
