# $NetBSD: buildlink3.mk,v 1.1 2016/12/13 01:19:20 marino Exp $

BUILDLINK_TREE+= gcc6-aux

.if !defined(GCC5_AUX_BUILDLINK3_MK)
GCC5_AUX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc6-aux+= gcc6-aux>=20160822
BUILDLINK_PKGSRCDIR.gcc6-aux?= ../../lang/gcc6-aux
BUILDLINK_DEPMETHOD.gcc6-aux?=	build

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"

pkgbase := gcc6-aux
.include "../../mk/pkg-build-options.mk"

.endif

BUILDLINK_TREE+= -gcc6-aux
