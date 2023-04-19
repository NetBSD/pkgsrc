# $NetBSD: buildlink3.mk,v 1.66 2023/04/19 08:08:24 adam Exp $

BUILDLINK_TREE+=	libkdcraw

.if !defined(LIBKDCRAW_BUILDLINK3_MK)
LIBKDCRAW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkdcraw+=	libkdcraw>=17.12.1
BUILDLINK_ABI_DEPENDS.libkdcraw?=	libkdcraw>=22.08.1nb5
BUILDLINK_PKGSRCDIR.libkdcraw?=		../../graphics/libkdcraw

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBKDCRAW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkdcraw
