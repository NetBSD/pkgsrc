# $NetBSD: buildlink3.mk,v 1.3 2022/04/12 22:27:58 tnn Exp $

BUILDLINK_TREE+=	libfido2

.if !defined(LIBFIDO2_BUILDLINK3_MK)
LIBFIDO2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libfido2+=	libfido2>=1.10.0
BUILDLINK_PKGSRCDIR.libfido2?=	../../security/libfido2

.include "../../devel/libcbor/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# LIBFIDO2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libfido2
