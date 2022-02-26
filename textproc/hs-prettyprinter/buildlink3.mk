# $NetBSD: buildlink3.mk,v 1.6 2022/02/26 03:58:29 pho Exp $

BUILDLINK_TREE+=	hs-prettyprinter

.if !defined(HS_PRETTYPRINTER_BUILDLINK3_MK)
HS_PRETTYPRINTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-prettyprinter+=	hs-prettyprinter>=1.7.1
BUILDLINK_ABI_DEPENDS.hs-prettyprinter+=	hs-prettyprinter>=1.7.1nb2
BUILDLINK_PKGSRCDIR.hs-prettyprinter?=		../../textproc/hs-prettyprinter
.endif	# HS_PRETTYPRINTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-prettyprinter
