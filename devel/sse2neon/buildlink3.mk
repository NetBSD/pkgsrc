# $NetBSD: buildlink3.mk,v 1.1 2026/01/05 16:58:17 adam Exp $

BUILDLINK_TREE+=	sse2neon

.if !defined(SSE2NEON_BUILDLINK3_MK)
SSE2NEON_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.sse2neon?=	build

BUILDLINK_API_DEPENDS.sse2neon+=	sse2neon>=1.7.0
BUILDLINK_PKGSRCDIR.sse2neon?=		../../devel/sse2neon
.endif	# SSE2NEON_BUILDLINK3_MK

BUILDLINK_TREE+=	-sse2neon
