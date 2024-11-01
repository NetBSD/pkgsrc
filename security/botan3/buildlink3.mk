# $NetBSD: buildlink3.mk,v 1.7 2024/11/01 07:22:45 nros Exp $

BUILDLINK_TREE+=	botan3

.if !defined(BOTAN3_BUILDLINK3_MK)
BOTAN3_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.botan3+=	botan3>=3.0.0
BUILDLINK_ABI_DEPENDS.botan3?=	botan3>=3.6.1
BUILDLINK_PKGSRCDIR.botan3?=	../../security/botan3

.include "../../devel/boost-libs/buildlink3.mk"
.endif	# BOTAN3_BUILDLINK3_MK

BUILDLINK_TREE+=	-botan3
