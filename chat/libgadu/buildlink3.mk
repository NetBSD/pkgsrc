# $NetBSD: buildlink3.mk,v 1.1 2020/01/20 17:25:10 adam Exp $

BUILDLINK_TREE+=	libgadu

.if !defined(LIBGADU_BUILDLINK3_MK)
LIBGADU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgadu+=	libgadu>=1.12.2
BUILDLINK_PKGSRCDIR.libgadu?=	../../chat/libgadu

.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# LIBGADU_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgadu
