# $NetBSD: buildlink3.mk,v 1.7 2023/10/09 04:54:46 pho Exp $

BUILDLINK_TREE+=	hs-fast-logger

.if !defined(HS_FAST_LOGGER_BUILDLINK3_MK)
HS_FAST_LOGGER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fast-logger+=	hs-fast-logger>=3.1.1
BUILDLINK_ABI_DEPENDS.hs-fast-logger+=	hs-fast-logger>=3.1.1nb4
BUILDLINK_PKGSRCDIR.hs-fast-logger?=	../../sysutils/hs-fast-logger

.include "../../devel/hs-auto-update/buildlink3.mk"
.include "../../sysutils/hs-easy-file/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.include "../../time/hs-unix-time/buildlink3.mk"
.endif	# HS_FAST_LOGGER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fast-logger
