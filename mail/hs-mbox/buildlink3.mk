# $NetBSD: buildlink3.mk,v 1.1 2025/03/07 17:40:26 pho Exp $

BUILDLINK_TREE+=	hs-mbox

.if !defined(HS_MBOX_BUILDLINK3_MK)
HS_MBOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-mbox+=	hs-mbox>=0.3.4
BUILDLINK_ABI_DEPENDS.hs-mbox+=	hs-mbox>=0.3.4
BUILDLINK_PKGSRCDIR.hs-mbox?=	../../mail/hs-mbox

.include "../../devel/hs-safe/buildlink3.mk"
.include "../../time/hs-time-locale-compat/buildlink3.mk"
.endif	# HS_MBOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-mbox
