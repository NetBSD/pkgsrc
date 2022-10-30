# $NetBSD: buildlink3.mk,v 1.14 2022/10/30 11:26:13 nros Exp $

BUILDLINK_TREE+=	pari

.if !defined(PARI_BUILDLINK3_MK)
PARI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pari+=	pari>=2.3.4
BUILDLINK_ABI_DEPENDS.pari+=	pari>=2.15.0
BUILDLINK_PKGSRCDIR.pari?=	../../math/pari

pkgbase := pari
.include "../../mk/pkg-build-options.mk"

PARI_LIB?=	pari
.if ${PKG_BUILD_OPTIONS.pari:Mgmp}
PARI_LIB=	pari-gmp
.  include "../../devel/gmp/buildlink3.mk"
.endif

.endif # PARI_BUILDLINK3_MK

BUILDLINK_TREE+=	-pari
