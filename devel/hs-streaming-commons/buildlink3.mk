# $NetBSD: buildlink3.mk,v 1.13 2024/05/09 01:32:13 pho Exp $

BUILDLINK_TREE+=	hs-streaming-commons

.if !defined(HS_STREAMING_COMMONS_BUILDLINK3_MK)
HS_STREAMING_COMMONS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-streaming-commons+=	hs-streaming-commons>=0.2.2
BUILDLINK_ABI_DEPENDS.hs-streaming-commons+=	hs-streaming-commons>=0.2.2.6nb2
BUILDLINK_PKGSRCDIR.hs-streaming-commons?=	../../devel/hs-streaming-commons

.include "../../devel/hs-async/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../devel/hs-random/buildlink3.mk"
.include "../../archivers/hs-zlib/buildlink3.mk"
.endif	# HS_STREAMING_COMMONS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-streaming-commons
