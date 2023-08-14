# $NetBSD: buildlink3.mk,v 1.2 2023/08/14 05:25:08 wiz Exp $

BUILDLINK_TREE+=	botan3

.if !defined(BOTAN3_BUILDLINK3_MK)
BOTAN3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.botan3+=	botan3>=3.0.0
BUILDLINK_ABI_DEPENDS.botan3?=	botan3>=3.0.0nb1
BUILDLINK_PKGSRCDIR.botan3?=	../../security/botan3

.include "../../devel/boost-libs/buildlink3.mk"
.endif	# BOTAN3_BUILDLINK3_MK

BUILDLINK_TREE+=	-botan3
