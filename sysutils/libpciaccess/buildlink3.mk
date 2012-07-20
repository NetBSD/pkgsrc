# $NetBSD: buildlink3.mk,v 1.3 2012/07/20 11:24:02 fhajny Exp $

BUILDLINK_TREE+=	libpciaccess

.if !defined(LIBPCIACCESS_BUILDLINK3_MK)
LIBPCIACCESS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpciaccess+=	libpciaccess>=0.10.4
BUILDLINK_PKGSRCDIR.libpciaccess?=	../../sysutils/libpciaccess

.include "../../devel/zlib/buildlink3.mk"
.endif # LIBPCIACCESS_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpciaccess
