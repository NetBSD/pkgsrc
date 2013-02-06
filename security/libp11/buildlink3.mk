# $NetBSD: buildlink3.mk,v 1.5 2013/02/06 23:21:01 jperkin Exp $

BUILDLINK_TREE+=	libp11

.if !defined(LIBP11_BUILDLINK3_MK)
LIBP11_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libp11+=	libp11>=0.2.4
BUILDLINK_ABI_DEPENDS.libp11+=	libp11>=0.2.6nb3
BUILDLINK_PKGSRCDIR.libp11?=	../../security/libp11

.include "../../devel/libltdl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # LIBP11_BUILDLINK3_MK

BUILDLINK_TREE+=	-libp11
