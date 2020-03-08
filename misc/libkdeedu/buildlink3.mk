# $NetBSD: buildlink3.mk,v 1.38 2020/03/08 16:47:56 wiz Exp $

BUILDLINK_TREE+=	libkdeedu

.if !defined(LIBKDEEDU_BUILDLINK3_MK)
LIBKDEEDU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkdeedu+=	libkdeedu>=4.8.0
BUILDLINK_ABI_DEPENDS.libkdeedu?=	libkdeedu>=4.14.3nb18
BUILDLINK_PKGSRCDIR.libkdeedu?=		../../misc/libkdeedu

.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# LIBKDEEDU_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkdeedu
