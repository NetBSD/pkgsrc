# $NetBSD: buildlink3.mk,v 1.24 2012/02/06 12:40:29 wiz Exp $

BUILDLINK_TREE+=	libkexif

.if !defined(LIBKEXIF_BUILDLINK3_MK)
LIBKEXIF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkexif+=	libkexif>=0.2.5
BUILDLINK_ABI_DEPENDS.libkexif?=	libkexif>=0.2.5nb15
BUILDLINK_PKGSRCDIR.libkexif?=	../../graphics/libkexif

.include "../../graphics/libexif/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.endif # LIBKEXIF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkexif
