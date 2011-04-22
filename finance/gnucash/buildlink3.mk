# $NetBSD: buildlink3.mk,v 1.13 2011/04/22 13:42:26 obache Exp $

BUILDLINK_TREE+=	gnucash

.if !defined(GNUCASH_BUILDLINK3_MK)
GNUCASH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnucash+=	gnucash>=2.1.0
BUILDLINK_ABI_DEPENDS.gnucash?=	gnucash>=2.4.5nb1
BUILDLINK_PKGSRCDIR.gnucash?=	../../finance/gnucash

.include "../../devel/glib2/buildlink3.mk"
.endif # GNUCASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnucash
