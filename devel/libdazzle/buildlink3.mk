# $NetBSD: buildlink3.mk,v 1.2 2020/01/22 09:44:41 nia Exp $

BUILDLINK_TREE+=	libdazzle

.if !defined(LIBDAZZLE_BUILDLINK3_MK)
LIBDAZZLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdazzle+=	libdazzle>=3.34
BUILDLINK_PKGSRCDIR.libdazzle?=		../../devel/libdazzle
BUILDLINK_INCDIRS.libdazzle+=		include/libdazzle-1.0

.include "../../x11/gtk3/buildlink3.mk"
.endif	# LIBDAZZLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdazzle
