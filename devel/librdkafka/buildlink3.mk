# $NetBSD: buildlink3.mk,v 1.4 2023/08/14 05:24:12 wiz Exp $

BUILDLINK_TREE+=	librdkafka

.if !defined(LIBRDKAFKA_BUILDLINK3_MK)
LIBRDKAFKA_BUILDLINK3_MK:=

BUILDLINK_ABI_DEPENDS.librdkafka+=	librdkafka>=1.3.0nb1
BUILDLINK_API_DEPENDS.librdkafka+=	librdkafka>=0.9.5
BUILDLINK_PKGSRCDIR.librdkafka?=	../../devel/librdkafka

.include "../../archivers/lz4/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.endif	# LIBRDKAFKA_BUILDLINK3_MK

BUILDLINK_TREE+=	-librdkafka
