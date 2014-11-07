# $NetBSD: buildlink3.mk,v 1.36 2014/11/07 19:39:24 adam Exp $

BUILDLINK_TREE+=	libkdcraw

.if !defined(LIBKDCRAW_BUILDLINK3_MK)
LIBKDCRAW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkdcraw+=	libkdcraw>=4.8.0
BUILDLINK_ABI_DEPENDS.libkdcraw?=	libkdcraw>=4.11.5nb5
BUILDLINK_PKGSRCDIR.libkdcraw?=	../../graphics/libkdcraw

.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# LIBKDCRAW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkdcraw
