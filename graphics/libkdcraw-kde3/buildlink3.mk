# $NetBSD: buildlink3.mk,v 1.6 2013/01/26 21:36:29 adam Exp $

BUILDLINK_TREE+=	libkdcraw

.if !defined(LIBKDCRAW_BUILDLINK3_MK)
LIBKDCRAW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkdcraw+=	libkdcraw>=0.1.1<4.0
BUILDLINK_ABI_DEPENDS.libkdcraw+=	libkdcraw>=0.1.9nb14
BUILDLINK_PKGSRCDIR.libkdcraw?=	../../graphics/libkdcraw-kde3

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.endif # LIBKDCRAW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkdcraw
