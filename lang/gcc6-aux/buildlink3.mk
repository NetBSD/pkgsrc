# $NetBSD: buildlink3.mk,v 1.6 2021/04/02 16:30:09 nia Exp $

BUILDLINK_TREE+=	gcc6-aux

.if !defined(GCC6_AUX_BUILDLINK3_MK)
GCC6_AUX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gcc6-aux+=	gcc6-aux>=20160822
BUILDLINK_ABI_DEPENDS.gcc6-aux?=	gcc6-aux>=20160822nb1
BUILDLINK_PKGSRCDIR.gcc6-aux?=		../../lang/gcc6-aux
BUILDLINK_DEPMETHOD.gcc6-aux?=		build

.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"

pkgbase := gcc6-aux
.include "../../mk/pkg-build-options.mk"
.endif

BUILDLINK_TREE+=	-gcc6-aux
