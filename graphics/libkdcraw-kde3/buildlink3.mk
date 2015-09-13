# $NetBSD: buildlink3.mk,v 1.19 2015/09/13 15:57:54 joerg Exp $

BUILDLINK_TREE+=	libkdcraw

.if !defined(LIBKDCRAW_BUILDLINK3_MK)
LIBKDCRAW_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkdcraw+=	libkdcraw>=0.1.1<4.0
BUILDLINK_ABI_DEPENDS.libkdcraw+=	libkdcraw>=0.1.9nb27
BUILDLINK_PKGSRCDIR.libkdcraw?=	../../graphics/libkdcraw-kde3

.include "../../graphics/lcms/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.endif # LIBKDCRAW_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkdcraw
