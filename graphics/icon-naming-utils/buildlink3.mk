# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:24:40 joerg Exp $

BUILDLINK_TREE+=	icon-naming-utils

.if !defined(ICON_NAMING_UTILS_BUILDLINK3_MK)
ICON_NAMING_UTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.icon-naming-utils+=	icon-naming-utils>=0.8.7
BUILDLINK_DEPMETHOD.icon-naming-utils?=		build
BUILDLINK_PKGSRCDIR.icon-naming-utils?=		../../graphics/icon-naming-utils
.endif # ICON_NAMING_UTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-icon-naming-utils
