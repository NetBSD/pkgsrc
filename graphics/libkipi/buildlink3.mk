# $NetBSD: buildlink3.mk,v 1.54 2018/01/01 21:18:09 adam Exp $

BUILDLINK_TREE+=	libkipi

.if !defined(LIBKIPI_BUILDLINK3_MK)
LIBKIPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkipi+=	libkipi>=4.8.0
BUILDLINK_ABI_DEPENDS.libkipi?=	libkipi>=15.08.3nb3
BUILDLINK_PKGSRCDIR.libkipi?=	../../graphics/libkipi

.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# LIBKIPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkipi
