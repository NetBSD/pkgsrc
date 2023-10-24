# $NetBSD: buildlink3.mk,v 1.5 2023/10/24 22:10:50 wiz Exp $

BUILDLINK_TREE+=	libfido2

.if !defined(LIBFIDO2_BUILDLINK3_MK)
LIBFIDO2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfido2+=	libfido2>=1.10.0
BUILDLINK_ABI_DEPENDS.libfido2?=		libfido2>=1.13.0nb1
BUILDLINK_PKGSRCDIR.libfido2?=		../../security/libfido2

.include "../../devel/libcbor/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# LIBFIDO2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfido2
