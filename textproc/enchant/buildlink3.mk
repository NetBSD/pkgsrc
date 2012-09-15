# $NetBSD: buildlink3.mk,v 1.16 2012/09/15 10:06:36 obache Exp $

BUILDLINK_TREE+=	enchant

.if !defined(ENCHANT_BUILDLINK3_MK)
ENCHANT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.enchant+=	enchant>=1.1.3
BUILDLINK_ABI_DEPENDS.enchant+=	enchant>=1.6.0nb5
BUILDLINK_PKGSRCDIR.enchant?=	../../textproc/enchant

# spelling libraries are loaded dynamically and do not need
# to be included here
.include "../../devel/glib2/buildlink3.mk"
.endif # ENCHANT_BUILDLINK3_MK

BUILDLINK_TREE+=	-enchant
