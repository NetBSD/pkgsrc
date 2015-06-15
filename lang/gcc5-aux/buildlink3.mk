# $NetBSD: buildlink3.mk,v 1.1 2015/06/15 09:46:27 marino Exp $

BUILDLINK_TREE+= gcc5-aux

.if !defined(GCC5_AUX_BUILDLINK3_MK)
GCC5_AUX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc5-aux+= gcc5-aux>=20150422
BUILDLINK_PKGSRCDIR.gcc5-aux?= ../../lang/gcc5-aux

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"

pkgbase := gcc5-aux
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.gcc5-aux:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
.endif
.endif

BUILDLINK_TREE+= -gcc5-aux
