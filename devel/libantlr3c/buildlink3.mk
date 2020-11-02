# $NetBSD: buildlink3.mk,v 1.1 2020/11/02 12:25:56 nia Exp $

BUILDLINK_TREE+=	libantlr3c

.if !defined(LIBANTLR3C_BUILDLINK3_MK)
LIBANTLR3C_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libantlr3c+=	libantlr3c>=3.4
BUILDLINK_PKGSRCDIR.libantlr3c?=	../../devel/libantlr3c
.endif	# LIBANTLR3C_BUILDLINK3_MK

BUILDLINK_TREE+=	-libantlr3c
