# $NetBSD: buildlink3.mk,v 1.79 2026/01/07 08:47:22 wiz Exp $

BUILDLINK_TREE+=	libkdcraw

.if !defined(LIBKDCRAW_BUILDLINK3_MK)
LIBKDCRAW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkdcraw+=	libkdcraw>=25.08.2
BUILDLINK_ABI_DEPENDS.libkdcraw?=	libkdcraw>=25.08.3nb1
BUILDLINK_PKGSRCDIR.libkdcraw?=		../../graphics/libkdcraw

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# LIBKDCRAW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkdcraw
