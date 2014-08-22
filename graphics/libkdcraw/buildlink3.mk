# $NetBSD: buildlink3.mk,v 1.35 2014/08/22 11:24:25 wiz Exp $

BUILDLINK_TREE+=	libkdcraw

.if !defined(LIBKDCRAW_BUILDLINK3_MK)
LIBKDCRAW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkdcraw+=	libkdcraw>=4.8.0
BUILDLINK_ABI_DEPENDS.libkdcraw?=	libkdcraw>=4.11.5nb4
BUILDLINK_PKGSRCDIR.libkdcraw?=	../../graphics/libkdcraw

.include "../../x11/kdelibs4/buildlink3.mk"
.endif	# LIBKDCRAW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkdcraw
