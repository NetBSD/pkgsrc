# $NetBSD: buildlink3.mk,v 1.4 2014/10/13 08:32:54 jperkin Exp $

BUILDLINK_TREE+=	libclucene

.if !defined(LIBCLUCENE_BUILDLINK3_MK)
LIBCLUCENE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libclucene+=	libclucene>=2.2.0
BUILDLINK_PKGSRCDIR.libclucene?=	../../textproc/libclucene
.endif # LIBCLUCENE_BUILDLINK3_MK

# boost-libs sets GCC_REQD, so we need to ensure we are in sync otherwise
# we may end up with the wrong libstdc++ runtime.
.include "../../devel/boost-libs/buildlink3.mk"
BUILDLINK_TREE+=	-libclucene
