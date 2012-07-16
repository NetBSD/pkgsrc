# $NetBSD: buildlink3.mk,v 1.3 2012/07/16 19:34:27 marino Exp $

BUILDLINK_TREE+= gcc-aux

.if !defined(GCC_AUX_BUILDLINK3_MK)
GCC_AUX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc-aux+= gcc-aux>=20120614
BUILDLINK_PKGSRCDIR.gcc-aux?= ../../lang/gcc-aux

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"

pkgbase := gcc-aux
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.gcc-aux:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
.endif
.endif

BUILDLINK_TREE+= -gcc-aux
