# $NetBSD: buildlink3.mk,v 1.3 2018/01/07 13:04:21 rillig Exp $

BUILDLINK_TREE+=	libsieve

.if !defined(LIBSIEVE_BUILDLINK3_MK)
LIBSIEVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsieve+=	libsieve>=2.2.5
BUILDLINK_PKGSRCDIR.libsieve?=		../../mail/libsieve
.endif # LIBSIEVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsieve
