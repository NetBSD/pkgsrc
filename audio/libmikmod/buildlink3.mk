# $NetBSD: buildlink3.mk,v 1.21 2020/01/20 21:26:52 nia Exp $

BUILDLINK_TREE+=	libmikmod

.if !defined(LIBMIKMOD_BUILDLINK3_MK)
LIBMIKMOD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmikmod+=	libmikmod>=3.1.9
BUILDLINK_ABI_DEPENDS.libmikmod+=	libmikmod>=3.2.0
BUILDLINK_PKGSRCDIR.libmikmod?=		../../audio/libmikmod

pkgbase := libmikmod
.include "../../mk/pkg-build-options.mk"
.endif # LIBMIKMOD_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmikmod
