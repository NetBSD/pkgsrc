# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:25:25 joerg Exp $

BUILDLINK_TREE+=	libpciaccess

.if !defined(LIBPCIACCESS_BUILDLINK3_MK)
LIBPCIACCESS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpciaccess+=	libpciaccess>=0.10.4
BUILDLINK_PKGSRCDIR.libpciaccess?=	../../sysutils/libpciaccess
.endif # LIBPCIACCESS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpciaccess
