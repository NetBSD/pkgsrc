# $NetBSD: buildlink3.mk,v 1.1 2025/03/08 03:14:16 pho Exp $

BUILDLINK_TREE+=	hs-io-streams-haproxy

.if !defined(HS_IO_STREAMS_HAPROXY_BUILDLINK3_MK)
HS_IO_STREAMS_HAPROXY_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-io-streams-haproxy+=	hs-io-streams-haproxy>=1.0.1
BUILDLINK_ABI_DEPENDS.hs-io-streams-haproxy+=	hs-io-streams-haproxy>=1.0.1.0
BUILDLINK_PKGSRCDIR.hs-io-streams-haproxy?=	../../net/hs-io-streams-haproxy

.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-io-streams/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.endif	# HS_IO_STREAMS_HAPROXY_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-io-streams-haproxy
