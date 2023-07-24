# $NetBSD: buildlink3.mk,v 1.1 2023/07/24 22:21:42 khorben Exp $

BUILDLINK_TREE+=        irssi

.if !defined(IRSSI_BUILDLINK3_MK)
IRSSI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.irssi+=    irssi>=1.4.4
BUILDLINK_ABI_DEPENDS.irssi+=    irssi>=1.4.4
BUILDLINK_PKGSRCDIR.irssi?=      ../../chat/irssi

.endif # IRSSI_BUILDLINK3_MK

BUILDLINK_TREE+=        -irssi
