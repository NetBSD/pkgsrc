# $NetBSD: buildlink3.mk,v 1.59 2020/11/05 09:06:55 ryoon Exp $

BUILDLINK_TREE+=	libkdcraw

.if !defined(LIBKDCRAW_BUILDLINK3_MK)
LIBKDCRAW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkdcraw+=	libkdcraw>=17.12.1
BUILDLINK_ABI_DEPENDS.libkdcraw?=		libkdcraw>=20.04.1nb2
BUILDLINK_PKGSRCDIR.libkdcraw?=		../../graphics/libkdcraw

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBKDCRAW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkdcraw
