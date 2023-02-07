# $NetBSD: buildlink3.mk,v 1.6 2023/02/07 01:41:06 pho Exp $

BUILDLINK_TREE+=	hs-fast-logger

.if !defined(HS_FAST_LOGGER_BUILDLINK3_MK)
HS_FAST_LOGGER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-fast-logger+=	hs-fast-logger>=3.1.1
BUILDLINK_ABI_DEPENDS.hs-fast-logger+=	hs-fast-logger>=3.1.1nb3
BUILDLINK_PKGSRCDIR.hs-fast-logger?=	../../sysutils/hs-fast-logger

.include "../../devel/hs-auto-update/buildlink3.mk"
.include "../../sysutils/hs-easy-file/buildlink3.mk"
.include "../../devel/hs-unix-compat/buildlink3.mk"
.include "../../time/hs-unix-time/buildlink3.mk"
.endif	# HS_FAST_LOGGER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-fast-logger
