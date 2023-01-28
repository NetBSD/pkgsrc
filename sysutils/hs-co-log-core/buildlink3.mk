# $NetBSD: buildlink3.mk,v 1.1 2023/01/28 05:43:27 pho Exp $

BUILDLINK_TREE+=	hs-co-log-core

.if !defined(HS_CO_LOG_CORE_BUILDLINK3_MK)
HS_CO_LOG_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-co-log-core+=	hs-co-log-core>=0.3.2
BUILDLINK_ABI_DEPENDS.hs-co-log-core+=	hs-co-log-core>=0.3.2.0
BUILDLINK_PKGSRCDIR.hs-co-log-core?=	../../sysutils/hs-co-log-core
.endif	# HS_CO_LOG_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-co-log-core
