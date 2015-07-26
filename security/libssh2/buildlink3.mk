# $NetBSD: buildlink3.mk,v 1.8 2015/07/26 17:15:34 nros Exp $

BUILDLINK_TREE+=	libssh2

.if !defined(LIBSSH2_BUILDLINK3_MK)
LIBSSH2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libssh2+=	libssh2>=0.18
BUILDLINK_ABI_DEPENDS.libssh2+=	libssh2>=1.6.0
BUILDLINK_PKGSRCDIR.libssh2?=	../../security/libssh2

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # LIBSSH2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libssh2
