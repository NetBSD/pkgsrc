# $NetBSD: buildlink3.mk,v 1.57 2018/08/16 18:54:29 adam Exp $

BUILDLINK_TREE+=	libkipi

.if !defined(LIBKIPI_BUILDLINK3_MK)
LIBKIPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkipi+=	libkipi>=4.8.0
BUILDLINK_ABI_DEPENDS.libkipi?=	libkipi>=15.08.3nb6
BUILDLINK_PKGSRCDIR.libkipi?=	../../graphics/libkipi

.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# LIBKIPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkipi
