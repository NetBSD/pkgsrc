# $NetBSD: buildlink3.mk,v 1.28 2025/09/27 09:57:37 wiz Exp $

BUILDLINK_TREE+=	libclucene

.if !defined(LIBCLUCENE_BUILDLINK3_MK)
LIBCLUCENE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libclucene+=	libclucene>=2.2.0
BUILDLINK_ABI_DEPENDS.libclucene+=	libclucene>=2.3.3.4nb28
BUILDLINK_PKGSRCDIR.libclucene?=	../../textproc/libclucene

# boost-libs sets GCC_REQD, so we need to ensure we are in sync otherwise
# we may end up with the wrong libstdc++ runtime.
.include "../../devel/boost-libs/buildlink3.mk"
.endif # LIBCLUCENE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libclucene
