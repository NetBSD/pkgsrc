# $NetBSD: buildlink3.mk,v 1.1 2016/06/07 11:57:30 jperkin Exp $

BUILDLINK_TREE+=	libtelnet

.if !defined(LIBTELNET_BUILDLINK3_MK)
LIBTELNET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libtelnet+=	libtelnet>=0.21
BUILDLINK_ABI_DEPENDS.libtelnet+=	libtelnet>=0.21
BUILDLINK_PKGSRCDIR.libtelnet?=		../../net/libtelnet

.endif # LIBTELNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-libtelnet
