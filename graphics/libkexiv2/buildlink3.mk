# $NetBSD: buildlink3.mk,v 1.50 2026/09/02 19:02:46 wiz Exp $

BUILDLINK_TREE+=	libkexiv2

.if !defined(LIBKEXIV2_BUILDLINK3_MK)
LIBKEXIV2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkexiv2+=	libkexiv2>=25.08.2
BUILDLINK_ABI_DEPENDS.libkexiv2?=	libkexiv2>=25.08.3nb4
BUILDLINK_PKGSRCDIR.libkexiv2?=		../../graphics/libkexiv2

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# LIBKEXIV2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkexiv2
