# $NetBSD: buildlink3.mk,v 1.1 2025/03/08 02:47:31 pho Exp $

BUILDLINK_TREE+=	hs-zlib-bindings

.if !defined(HS_ZLIB_BINDINGS_BUILDLINK3_MK)
HS_ZLIB_BINDINGS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-zlib-bindings+=	hs-zlib-bindings>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-zlib-bindings+=	hs-zlib-bindings>=0.1.1.5
BUILDLINK_PKGSRCDIR.hs-zlib-bindings?=		../../archivers/hs-zlib-bindings

.include "../../archivers/hs-zlib/buildlink3.mk"
.endif	# HS_ZLIB_BINDINGS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-zlib-bindings
