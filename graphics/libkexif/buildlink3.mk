# $NetBSD: buildlink3.mk,v 1.27 2012/06/14 07:43:42 sbd Exp $

BUILDLINK_TREE+=	libkexif

.if !defined(LIBKEXIF_BUILDLINK3_MK)
LIBKEXIF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkexif+=	libkexif>=0.2.5
BUILDLINK_ABI_DEPENDS.libkexif+=	libkexif>=0.2.5nb17
BUILDLINK_PKGSRCDIR.libkexif?=	../../graphics/libkexif

.include "../../graphics/libexif/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.endif # LIBKEXIF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkexif
