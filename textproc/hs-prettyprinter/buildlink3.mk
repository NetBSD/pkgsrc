# $NetBSD: buildlink3.mk,v 1.12 2025/03/05 03:40:01 pho Exp $

BUILDLINK_TREE+=	hs-prettyprinter

.if !defined(HS_PRETTYPRINTER_BUILDLINK3_MK)
HS_PRETTYPRINTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-prettyprinter+=	hs-prettyprinter>=1.7.1
BUILDLINK_ABI_DEPENDS.hs-prettyprinter+=	hs-prettyprinter>=1.7.1nb8
BUILDLINK_PKGSRCDIR.hs-prettyprinter?=		../../textproc/hs-prettyprinter
.endif	# HS_PRETTYPRINTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-prettyprinter
