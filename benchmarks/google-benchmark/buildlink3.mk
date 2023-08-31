# $NetBSD: buildlink3.mk,v 1.4 2023/08/31 17:22:52 adam Exp $

BUILDLINK_TREE+=	google-benchmark

.if !defined(GOOGLE_BENCHMARK_BUILDLINK3_MK)
GOOGLE_BENCHMARK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.google-benchmark+=	google-benchmark>=1.1.0
BUILDLINK_DEPMETHOD.google-benchmark?=		build
BUILDLINK_ABI_DEPENDS.google-benchmark+=	google-benchmark>=1.8.2nb1
BUILDLINK_PKGSRCDIR.google-benchmark?=		../../benchmarks/google-benchmark
.endif	# GOOGLE_BENCHMARK_BUILDLINK3_MK

BUILDLINK_TREE+=	-google-benchmark
