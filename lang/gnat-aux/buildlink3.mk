# $NetBSD: buildlink3.mk,v 1.1.1.1 2011/02/01 20:32:56 drochner Exp $

BUILDLINK_TREE+=	gnat-aux

.if !defined(GNAT_AUX_BUILDLINK3_MK)
GNAT_AUX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnat-aux+=	gnat-aux>=20101120
BUILDLINK_PKGSRCDIR.gnat-aux?=	../../lang/gnat-aux

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.endif	# GNAT_AUX_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnat-aux
