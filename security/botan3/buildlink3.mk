# $NetBSD: buildlink3.mk,v 1.3 2023/10/19 15:21:40 wiz Exp $

BUILDLINK_TREE+=	botan3

.if !defined(BOTAN3_BUILDLINK3_MK)
BOTAN3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.botan3+=	botan3>=3.0.0
BUILDLINK_ABI_DEPENDS.botan3?=	botan3>=3.2.0
BUILDLINK_PKGSRCDIR.botan3?=	../../security/botan3

.include "../../devel/boost-libs/buildlink3.mk"
.endif	# BOTAN3_BUILDLINK3_MK

BUILDLINK_TREE+=	-botan3
