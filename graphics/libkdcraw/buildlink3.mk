# $NetBSD: buildlink3.mk,v 1.82 2026/09/02 19:02:45 wiz Exp $

BUILDLINK_TREE+=	libkdcraw

.if !defined(LIBKDCRAW_BUILDLINK3_MK)
LIBKDCRAW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkdcraw+=	libkdcraw>=25.08.2
BUILDLINK_ABI_DEPENDS.libkdcraw?=	libkdcraw>=25.08.3nb5
BUILDLINK_PKGSRCDIR.libkdcraw?=		../../graphics/libkdcraw

.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# LIBKDCRAW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkdcraw
