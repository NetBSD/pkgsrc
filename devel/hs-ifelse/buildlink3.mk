# $NetBSD: buildlink3.mk,v 1.5 2025/03/05 03:39:17 pho Exp $

BUILDLINK_TREE+=	hs-ifelse

.if !defined(HS_IFELSE_BUILDLINK3_MK)
HS_IFELSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ifelse+=	hs-ifelse>=0.85
BUILDLINK_ABI_DEPENDS.hs-ifelse+=	hs-ifelse>=0.85nb4
BUILDLINK_PKGSRCDIR.hs-ifelse?=		../../devel/hs-ifelse
.endif	# HS_IFELSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ifelse
