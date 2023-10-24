# $NetBSD: buildlink3.mk,v 1.9 2023/10/24 22:10:50 wiz Exp $

BUILDLINK_TREE+=	libp11

.if !defined(LIBP11_BUILDLINK3_MK)
LIBP11_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libp11+=	libp11>=0.2.4
BUILDLINK_ABI_DEPENDS.libp11+=	libp11>=0.4.11nb1
BUILDLINK_PKGSRCDIR.libp11?=	../../security/libp11

.include "../../devel/libltdl/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # LIBP11_BUILDLINK3_MK

BUILDLINK_TREE+=	-libp11
