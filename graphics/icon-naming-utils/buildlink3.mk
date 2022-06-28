# $NetBSD: buildlink3.mk,v 1.4 2022/06/28 11:34:02 wiz Exp $

BUILDLINK_TREE+=	icon-naming-utils

.if !defined(ICON_NAMING_UTILS_BUILDLINK3_MK)
ICON_NAMING_UTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.icon-naming-utils+=	icon-naming-utils>=0.8.7
BUILDLINK_DEPMETHOD.icon-naming-utils?=		build
BUILDLINK_ABI_DEPENDS.icon-naming-utils?=		icon-naming-utils>=0.8.90nb10
BUILDLINK_PKGSRCDIR.icon-naming-utils?=		../../graphics/icon-naming-utils
.endif # ICON_NAMING_UTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-icon-naming-utils
