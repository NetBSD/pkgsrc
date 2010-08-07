# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/08/07 02:16:37 obache Exp $

BUILDLINK_TREE+=	ibus-table-extraphrase

.if !defined(IBUS_TABLE_EXTRAPHRASE_BUILDLINK3_MK)
IBUS_TABLE_EXTRAPHRASE_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.ibus-table-extraphrase?=	build
BUILDLINK_API_DEPENDS.ibus-table-extraphrase+=	ibus-table-extraphrase>=1.1.0.20090415
BUILDLINK_PKGSRCDIR.ibus-table-extraphrase?=	../../inputmethod/ibus-table-extraphrase

.endif	# IBUS_TABLE_EXTRAPHRASE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ibus-table-extraphrase
