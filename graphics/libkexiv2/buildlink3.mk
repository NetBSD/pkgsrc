# $NetBSD: buildlink3.mk,v 1.25 2020/03/10 22:08:51 wiz Exp $

BUILDLINK_TREE+=	libkexiv2

.if !defined(LIBKEXIV2_BUILDLINK3_MK)
LIBKEXIV2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkexiv2+=	libkexiv2>=17.12.1
BUILDLINK_ABI_DEPENDS.libkexiv2?=		libkexiv2>=19.12.1nb2
BUILDLINK_PKGSRCDIR.libkexiv2?=		../../graphics/libkexiv2

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBKEXIV2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkexiv2
