# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:03:56 rillig Exp $

BUILDLINK_TREE+=	google-benchmark

.if !defined(GOOGLE_BENCHMARK_BUILDLINK3_MK)
GOOGLE_BENCHMARK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.google-benchmark+=	google-benchmark>=1.1.0
BUILDLINK_DEPMETHOD.google-benchmark?=		build
BUILDLINK_PKGSRCDIR.google-benchmark?=		../../benchmarks/google-benchmark
.endif	# GOOGLE_BENCHMARK_BUILDLINK3_MK

BUILDLINK_TREE+=	-google-benchmark
