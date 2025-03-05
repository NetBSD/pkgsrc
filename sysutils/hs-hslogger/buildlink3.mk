# $NetBSD: buildlink3.mk,v 1.9 2025/03/05 03:39:53 pho Exp $

BUILDLINK_TREE+=	hs-hslogger

.if !defined(HS_HSLOGGER_BUILDLINK3_MK)
HS_HSLOGGER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hslogger+=	hs-hslogger>=1.3.1
BUILDLINK_ABI_DEPENDS.hs-hslogger+=	hs-hslogger>=1.3.1.1nb3
BUILDLINK_PKGSRCDIR.hs-hslogger?=	../../sysutils/hs-hslogger

.include "../../devel/hs-old-locale/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.include "../../net/hs-network-bsd/buildlink3.mk"
.endif	# HS_HSLOGGER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hslogger
