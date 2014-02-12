# $NetBSD: buildlink3.mk,v 1.6 2014/02/12 23:18:33 tron Exp $

BUILDLINK_TREE+=	libssh2

.if !defined(LIBSSH2_BUILDLINK3_MK)
LIBSSH2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libssh2+=	libssh2>=0.18
BUILDLINK_ABI_DEPENDS.libssh2+=	libssh2>=1.2.2nb3
BUILDLINK_PKGSRCDIR.libssh2?=	../../security/libssh2

.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif # LIBSSH2_BUILDLINK3_MK

BUILDLINK_TREE+=	-libssh2
