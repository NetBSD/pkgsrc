# $NetBSD: buildlink3.mk,v 1.91 2024/11/01 00:52:12 wiz Exp $

BUILDLINK_TREE+=	libkipi

.if !defined(LIBKIPI_BUILDLINK3_MK)
LIBKIPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkipi+=	libkipi>=17.12.1
BUILDLINK_ABI_DEPENDS.libkipi?=	libkipi>=23.08.4nb3
BUILDLINK_PKGSRCDIR.libkipi?=	../../graphics/libkipi

.include "../../x11/kxmlgui/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBKIPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkipi
