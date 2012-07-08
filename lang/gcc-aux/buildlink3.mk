# $NetBSD: buildlink3.mk,v 1.1 2012/07/08 19:30:38 marino Exp $

BUILDLINK_TREE+= gcc-aux

.if !defined(GCC_AUX_BUILDLINK3_MK)
GCC_AUX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc-aux+= gcc-aux>=20120614
BUILDLINK_PKGSRCDIR.gcc-aux?= ../../lang/gcc-aux

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.endif

BUILDLINK_TREE+= -gcc-aux
