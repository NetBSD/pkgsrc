# $NetBSD: buildlink3.mk,v 1.70 2020/12/04 04:55:58 riastradh Exp $

BUILDLINK_TREE+=	libkipi

.if !defined(LIBKIPI_BUILDLINK3_MK)
LIBKIPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkipi+=	libkipi>=17.12.1
BUILDLINK_ABI_DEPENDS.libkipi?=	libkipi>=20.04.1nb4
BUILDLINK_PKGSRCDIR.libkipi?=	../../graphics/libkipi

.include "../../x11/kxmlgui/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBKIPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkipi
