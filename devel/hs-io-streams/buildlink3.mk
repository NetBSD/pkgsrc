# $NetBSD: buildlink3.mk,v 1.1 2025/03/08 02:51:31 pho Exp $

BUILDLINK_TREE+=	hs-io-streams

.if !defined(HS_IO_STREAMS_BUILDLINK3_MK)
HS_IO_STREAMS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-io-streams+=	hs-io-streams>=1.5.2
BUILDLINK_ABI_DEPENDS.hs-io-streams+=	hs-io-streams>=1.5.2.2
BUILDLINK_PKGSRCDIR.hs-io-streams?=	../../devel/hs-io-streams

.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../archivers/hs-zlib-bindings/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.endif	# HS_IO_STREAMS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-io-streams
