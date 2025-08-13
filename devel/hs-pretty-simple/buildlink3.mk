# $NetBSD: buildlink3.mk,v 1.15 2025/08/13 11:06:53 pho Exp $

BUILDLINK_TREE+=	hs-pretty-simple

.if !defined(HS_PRETTY_SIMPLE_BUILDLINK3_MK)
HS_PRETTY_SIMPLE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-pretty-simple+=	hs-pretty-simple>=4.1.3
BUILDLINK_ABI_DEPENDS.hs-pretty-simple+=	hs-pretty-simple>=4.1.3.0nb3
BUILDLINK_PKGSRCDIR.hs-pretty-simple?=		../../devel/hs-pretty-simple

.include "../../textproc/hs-prettyprinter/buildlink3.mk"
.include "../../textproc/hs-prettyprinter-ansi-terminal/buildlink3.mk"
.endif	# HS_PRETTY_SIMPLE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-pretty-simple
