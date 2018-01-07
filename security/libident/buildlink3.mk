# $NetBSD: buildlink3.mk,v 1.8 2018/01/07 13:04:29 rillig Exp $

BUILDLINK_TREE+=	libident

.if !defined(LIBIDENT_BUILDLINK3_MK)
LIBIDENT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libident+=	libident>=0.22
BUILDLINK_ABI_DEPENDS.libident+=	libident>=0.22nb1
BUILDLINK_PKGSRCDIR.libident?=		../../security/libident
.endif # LIBIDENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libident
