# $NetBSD: buildlink3.mk,v 1.3 2021/12/08 16:02:05 adam Exp $

BUILDLINK_TREE+=	harfbuzz-icu

.if !defined(HARFBUZZ_ICU_BUILDLINK3_MK)
HARFBUZZ_ICU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.harfbuzz-icu+=	harfbuzz-icu>=2.1.1
BUILDLINK_ABI_DEPENDS.harfbuzz-icu+=	harfbuzz-icu>=3.1.2
BUILDLINK_PKGSRCDIR.harfbuzz-icu?=	../../fonts/harfbuzz-icu

.include "../../fonts/harfbuzz/buildlink3.mk"
.endif	# HARFBUZZ_ICU_BUILDLINK3_MK

BUILDLINK_TREE+=	-harfbuzz-icu
