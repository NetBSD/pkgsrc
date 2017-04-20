# $NetBSD: buildlink3.mk,v 1.1 2017/04/20 08:04:11 fhajny Exp $

BUILDLINK_TREE+=	librdkafka

.if !defined(LIBRDKAFKA_BUILDLINK3_MK)
LIBRDKAFKA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.librdkafka+=	librdkafka>=0.9.5
BUILDLINK_PKGSRCDIR.librdkafka?=	../../devel/librdkafka

.include "../../archivers/lz4/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif	# LIBRDKAFKA_BUILDLINK3_MK

BUILDLINK_TREE+=	-librdkafka
