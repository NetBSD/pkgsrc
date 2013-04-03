# $NetBSD: buildlink3.mk,v 1.1 2013/04/03 12:03:29 markd Exp $

BUILDLINK_TREE+=	libkmahjongg

.if !defined(LIBKMAHJONGG_BUILDLINK3_MK)
LIBKMAHJONGG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkmahjongg+=	libkmahjongg>=4.10.2
BUILDLINK_PKGSRCDIR.libkmahjongg?=	../../games/libkmahjongg

.endif	# LIBKMAHJONGG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkmahjongg
