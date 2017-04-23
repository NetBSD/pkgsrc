# $NetBSD: buildlink3.mk,v 1.31 2017/04/23 09:58:31 wiz Exp $

BUILDLINK_TREE+=	icu

.if !defined(ICU_BUILDLINK3_MK)
ICU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.icu+=	icu>=3.4
BUILDLINK_ABI_DEPENDS.icu+=	icu>=58.1
BUILDLINK_PKGSRCDIR.icu?=	../../textproc/icu
.endif # ICU_BUILDLINK3_MK

# icu uses char16_t in a central header file, which is added by c++11
CXXFLAGS+=	-std=c++11

BUILDLINK_TREE+=	-icu
