# $NetBSD: buildlink3.mk,v 1.39 2025/04/24 14:14:27 wiz Exp $

BUILDLINK_TREE+=	kipi-plugins

.if !defined(KIPI_PLUGINS_BUILDLINK3_MK)
KIPI_PLUGINS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kipi-plugins+=	kipi-plugins>=19.08.3
BUILDLINK_ABI_DEPENDS.kipi-plugins?=	kipi-plugins>=23.08.4nb10
BUILDLINK_PKGSRCDIR.kipi-plugins?=	../../graphics/kipi-plugins

.include "../../graphics/libkipi/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KIPI_PLUGINS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kipi-plugins
