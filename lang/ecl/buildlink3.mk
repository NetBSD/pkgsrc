# $NetBSD: buildlink3.mk,v 1.7 2014/04/21 13:25:53 wiz Exp $

BUILDLINK_TREE+=	ecl

.if !defined(ECL_BUILDLINK3_MK)
ECL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ecl+=	ecl>=10.3.1
BUILDLINK_ABI_DEPENDS.ecl+=	ecl>=13.5.1nb1
BUILDLINK_PKGSRCDIR.ecl?=	../../lang/ecl

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.endif # ECL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ecl
