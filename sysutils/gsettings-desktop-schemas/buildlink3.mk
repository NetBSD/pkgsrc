# $NetBSD: buildlink3.mk,v 1.1 2012/08/23 13:38:03 prlw1 Exp $

# Just for the pkg_config .pc file
BUILDLINK_TREE+=	gsettings-desktop-schemas

.if !defined(GSETTINGS_DESKTOP_SCHEMAS_BUILDLINK3_MK)
GSETTINGS_DESKTOP_SCHEMAS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gsettings-desktop-schemas+=	gsettings-desktop-schemas>=3.4.2
BUILDLINK_PKGSRCDIR.gsettings-desktop-schemas?=	../../sysutils/gsettings-desktop-schemas

.endif # GSETTINGS_DESKTOP_SCHEMAS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gsettings-desktop-schemas
