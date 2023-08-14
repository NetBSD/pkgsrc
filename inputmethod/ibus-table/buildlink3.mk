# $NetBSD: buildlink3.mk,v 1.5 2023/08/14 05:24:40 wiz Exp $

BUILDLINK_TREE+=	ibus-table

.if !defined(IBUS_TABLE_BUILDLINK3_MK)
IBUS_TABLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ibus-table+=	ibus-table>=1.2.0.20100111
BUILDLINK_API_DEPENDS.ibus-table+=	ibus-table>=1.8.0
BUILDLINK_ABI_DEPENDS.ibus-table?=	ibus-table>=1.9.2nb6
BUILDLINK_PKGSRCDIR.ibus-table?=	../../inputmethod/ibus-table

.endif	# IBUS_TABLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ibus-table
