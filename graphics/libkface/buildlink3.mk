# $NetBSD: buildlink3.mk,v 1.20 2014/11/07 19:39:25 adam Exp $

BUILDLINK_TREE+=	libkface

.if !defined(LIBKFACE_BUILDLINK3_MK)
LIBKFACE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkface+=	libkface>=2.5.0
BUILDLINK_ABI_DEPENDS.libkface?=	libkface>=3.5.0nb6
BUILDLINK_PKGSRCDIR.libkface?=	../../graphics/libkface

.include "../../graphics/opencv/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# LIBKFACE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkface
