# $NetBSD: buildlink3.mk,v 1.4 2024/05/09 01:31:49 pho Exp $

BUILDLINK_TREE+=	hs-concurrent-output

.if !defined(HS_CONCURRENT_OUTPUT_BUILDLINK3_MK)
HS_CONCURRENT_OUTPUT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-concurrent-output+=	hs-concurrent-output>=1.10.21
BUILDLINK_ABI_DEPENDS.hs-concurrent-output+=	hs-concurrent-output>=1.10.21nb1
BUILDLINK_PKGSRCDIR.hs-concurrent-output?=	../../devel/hs-concurrent-output

.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-terminal-size/buildlink3.mk"
.endif	# HS_CONCURRENT_OUTPUT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-concurrent-output
