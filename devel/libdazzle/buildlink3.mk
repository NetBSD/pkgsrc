# $NetBSD: buildlink3.mk,v 1.23 2026/06/11 07:16:50 wiz Exp $

BUILDLINK_TREE+=	libdazzle

.if !defined(LIBDAZZLE_BUILDLINK3_MK)
LIBDAZZLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdazzle+=	libdazzle>=3.34
BUILDLINK_ABI_DEPENDS.libdazzle?=		libdazzle>=3.38.0nb24
BUILDLINK_PKGSRCDIR.libdazzle?=		../../devel/libdazzle
BUILDLINK_INCDIRS.libdazzle+=		include/libdazzle-1.0

.include "../../x11/gtk3/buildlink3.mk"
.endif	# LIBDAZZLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdazzle
