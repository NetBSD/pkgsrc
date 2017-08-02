# $NetBSD: buildlink3.mk,v 1.2 2017/08/02 15:49:24 fhajny Exp $

BUILDLINK_TREE+=	librdkafka

.if !defined(LIBRDKAFKA_BUILDLINK3_MK)
LIBRDKAFKA_BUILDLINK3_MK:=

BUILDLINK_ABI_DEPENDS.librdkafka+=	librdkafka>=0.11.0
BUILDLINK_API_DEPENDS.librdkafka+=	librdkafka>=0.9.5
BUILDLINK_PKGSRCDIR.librdkafka?=	../../devel/librdkafka

.include "../../archivers/lz4/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif	# LIBRDKAFKA_BUILDLINK3_MK

BUILDLINK_TREE+=	-librdkafka
