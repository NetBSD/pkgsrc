# $NetBSD: buildlink3.mk,v 1.10 2024/07/31 17:10:10 wiz Exp $

BUILDLINK_TREE+=	ecl

.if !defined(ECL_BUILDLINK3_MK)
ECL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ecl+=	ecl>=16.0.0
BUILDLINK_ABI_DEPENDS.ecl+=	ecl>=16.0.0
BUILDLINK_PKGSRCDIR.ecl?=	../../lang/ecl

pkgbase := ecl
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.ecl:Mffi}
.include "../../devel/libffi/buildlink3.mk"
.endif

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.endif # ECL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ecl
