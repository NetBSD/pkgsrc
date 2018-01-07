# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:05 rillig Exp $

BUILDLINK_TREE+=	libffcall

.if !defined(LIBFFCALL_BUILDLINK3_MK)
LIBFFCALL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libffcall+=	libffcall>=2.0
BUILDLINK_PKGSRCDIR.libffcall?=		../../devel/libffcall
.endif	# LIBFFCALL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libffcall
