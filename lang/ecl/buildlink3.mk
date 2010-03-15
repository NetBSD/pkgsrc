# $NetBSD: buildlink3.mk,v 1.4 2010/03/15 05:20:13 asau Exp $

BUILDLINK_TREE+=	ecl

.if !defined(ECL_BUILDLINK3_MK)
ECL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ecl+=	ecl>=10.3.1
BUILDLINK_PKGSRCDIR.ecl?=	../../lang/ecl

.include "../../devel/boehm-gc/buildlink3.mk"
.include "../../devel/gmp/buildlink3.mk"
.endif # ECL_BUILDLINK3_MK

BUILDLINK_TREE+=	-ecl
