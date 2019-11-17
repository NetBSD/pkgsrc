# $NetBSD: buildlink3.mk,v 1.1 2019/11/17 02:15:38 markd Exp $

BUILDLINK_TREE+=	libkexiv2-kde4

.if !defined(LIBKEXIV2_KDE4_BUILDLINK3_MK)
LIBKEXIV2_KDE4_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkexiv2-kde4+=	libkexiv2-kde4>=4.8.0
BUILDLINK_PKGSRCDIR.libkexiv2-kde4?=		../../graphics/libkexiv2-kde4

.endif	# LIBKEXIV2_KDE4_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkexiv2-kde4
