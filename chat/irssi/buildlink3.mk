# $NetBSD: buildlink3.mk,v 1.2 2024/06/06 11:03:28 jperkin Exp $

BUILDLINK_TREE+=	irssi

.if !defined(IRSSI_BUILDLINK3_MK)
IRSSI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.irssi+=	irssi>=1.4.5
BUILDLINK_ABI_DEPENDS.irssi+=	irssi>=1.4.5
BUILDLINK_PKGSRCDIR.irssi?=	../../chat/irssi

.endif # IRSSI_BUILDLINK3_MK

BUILDLINK_TREE+=	-irssi
