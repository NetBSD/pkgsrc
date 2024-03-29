# $NetBSD: buildlink3.mk,v 1.11 2023/10/24 22:10:51 wiz Exp $

BUILDLINK_TREE+=	libssh2

.if !defined(LIBSSH2_BUILDLINK3_MK)
LIBSSH2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libssh2+=	libssh2>=0.18
BUILDLINK_ABI_DEPENDS.libssh2+=	libssh2>=1.11.0nb1
BUILDLINK_PKGSRCDIR.libssh2?=	../../security/libssh2

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # LIBSSH2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libssh2
