# $NetBSD: buildlink3.mk,v 1.14 2013/07/05 13:29:36 ryoon Exp $

BUILDLINK_TREE+=	libkface

.if !defined(LIBKFACE_BUILDLINK3_MK)
LIBKFACE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkface+=	libkface>=2.5.0
BUILDLINK_ABI_DEPENDS.libkface?=	libkface>=3.2.0nb4
BUILDLINK_PKGSRCDIR.libkface?=	../../graphics/libkface

.include "../../graphics/opencv/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# LIBKFACE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkface
