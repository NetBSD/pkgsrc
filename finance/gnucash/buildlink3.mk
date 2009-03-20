# $NetBSD: buildlink3.mk,v 1.12 2009/03/20 19:24:33 joerg Exp $

BUILDLINK_TREE+=	gnucash

.if !defined(GNUCASH_BUILDLINK3_MK)
GNUCASH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnucash+=	gnucash>=2.1.0
BUILDLINK_ABI_DEPENDS.gnucash?=	gnucash>=2.2.3nb2
BUILDLINK_PKGSRCDIR.gnucash?=	../../finance/gnucash

.include "../../devel/glib2/buildlink3.mk"
.endif # GNUCASH_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnucash
