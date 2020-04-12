# $NetBSD: buildlink3.mk,v 1.56 2020/04/12 08:27:56 adam Exp $

BUILDLINK_TREE+=	libkdcraw

.if !defined(LIBKDCRAW_BUILDLINK3_MK)
LIBKDCRAW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkdcraw+=	libkdcraw>=17.12.1
BUILDLINK_ABI_DEPENDS.libkdcraw?=		libkdcraw>=19.12.1nb3
BUILDLINK_PKGSRCDIR.libkdcraw?=		../../graphics/libkdcraw

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBKDCRAW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkdcraw
