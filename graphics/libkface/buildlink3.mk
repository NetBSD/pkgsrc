# $NetBSD: buildlink3.mk,v 1.23 2016/03/05 11:27:49 jperkin Exp $

BUILDLINK_TREE+=	libkface

.if !defined(LIBKFACE_BUILDLINK3_MK)
LIBKFACE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkface+=	libkface>=2.5.0
BUILDLINK_ABI_DEPENDS.libkface?=	libkface>=4.13.0nb1
BUILDLINK_PKGSRCDIR.libkface?=	../../graphics/libkface

.include "../../graphics/opencv/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# LIBKFACE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkface
