# $NetBSD: buildlink3.mk,v 1.2 2026/06/10 13:20:17 adam Exp $

BUILDLINK_TREE+=	clickhouse-cpp

.if !defined(CLICKHOUSE_CPP_BUILDLINK3_MK)
CLICKHOUSE_CPP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.clickhouse-cpp+=	clickhouse-cpp>=2.6.1
BUILDLINK_PKGSRCDIR.clickhouse-cpp?=	../../databases/clickhouse-cpp

.include "../../archivers/lz4/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../devel/abseil/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.endif	# CLICKHOUSE_CPP_BUILDLINK3_MK

BUILDLINK_TREE+=	-clickhouse-cpp
