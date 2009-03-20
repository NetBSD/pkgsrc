# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:41 joerg Exp $

BUILDLINK_TREE+=	kipi-plugins

.if !defined(KIPI_PLUGINS_BUILDLINK3_MK)
KIPI_PLUGINS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kipi-plugins+=	kipi-plugins>=0.1.4nb6
BUILDLINK_PKGSRCDIR.kipi-plugins?=	../../graphics/kipi-plugins
.endif # KIPI_PLUGINS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kipi-plugins
