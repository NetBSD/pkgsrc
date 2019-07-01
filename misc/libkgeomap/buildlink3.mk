# $NetBSD: buildlink3.mk,v 1.33 2019/07/01 04:07:50 ryoon Exp $

BUILDLINK_TREE+=	libkgeomap

.if !defined(LIBKGEOMAP_BUILDLINK3_MK)
LIBKGEOMAP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkgeomap+=	libkgeomap>=2.5.0
BUILDLINK_ABI_DEPENDS.libkgeomap?=	libkgeomap>=4.13.0nb11
BUILDLINK_PKGSRCDIR.libkgeomap?=	../../misc/libkgeomap

.include "../../misc/marble/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# LIBKGEOMAP_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkgeomap
