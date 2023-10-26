# $NetBSD: buildlink3.mk,v 1.10 2023/10/26 05:11:20 pho Exp $

BUILDLINK_TREE+=	hs-unliftio-core

.if !defined(HS_UNLIFTIO_CORE_BUILDLINK3_MK)
HS_UNLIFTIO_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-unliftio-core+=	hs-unliftio-core>=0.2.1
BUILDLINK_ABI_DEPENDS.hs-unliftio-core+=	hs-unliftio-core>=0.2.1.0
BUILDLINK_PKGSRCDIR.hs-unliftio-core?=		../../devel/hs-unliftio-core
.endif	# HS_UNLIFTIO_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-unliftio-core
