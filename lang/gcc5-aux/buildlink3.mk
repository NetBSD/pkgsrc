# $NetBSD: buildlink3.mk,v 1.2 2016/11/26 18:23:25 marino Exp $

BUILDLINK_TREE+= gcc5-aux

.if !defined(GCC5_AUX_BUILDLINK3_MK)
GCC5_AUX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc5-aux+= gcc5-aux>=20150422
BUILDLINK_PKGSRCDIR.gcc5-aux?= ../../lang/gcc5-aux
BUILDLINK_DEPMETHOD.gcc5-aux?=	build

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"

pkgbase := gcc5-aux
.include "../../mk/pkg-build-options.mk"

.endif

BUILDLINK_TREE+= -gcc5-aux
