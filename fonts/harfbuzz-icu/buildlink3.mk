# $NetBSD: buildlink3.mk,v 1.8 2026/09/27 11:36:09 tnn Exp $

BUILDLINK_TREE+=	harfbuzz-icu

.if !defined(HARFBUZZ_ICU_BUILDLINK3_MK)
HARFBUZZ_ICU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.harfbuzz-icu+=	harfbuzz-icu>=2.1.1
BUILDLINK_ABI_DEPENDS.harfbuzz-icu+=	harfbuzz-icu>=14.5.0nb1
BUILDLINK_PKGSRCDIR.harfbuzz-icu?=	../../fonts/harfbuzz-icu

.include "../../fonts/harfbuzz/buildlink3.mk"
.endif	# HARFBUZZ_ICU_BUILDLINK3_MK

BUILDLINK_TREE+=	-harfbuzz-icu
