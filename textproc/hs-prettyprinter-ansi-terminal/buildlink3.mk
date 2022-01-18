# $NetBSD: buildlink3.mk,v 1.3 2022/01/18 02:48:27 pho Exp $

BUILDLINK_TREE+=	hs-prettyprinter-ansi-terminal

.if !defined(HS_PRETTYPRINTER_ANSI_TERMINAL_BUILDLINK3_MK)
HS_PRETTYPRINTER_ANSI_TERMINAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-prettyprinter-ansi-terminal+=	hs-prettyprinter-ansi-terminal>=1.1.2
BUILDLINK_ABI_DEPENDS.hs-prettyprinter-ansi-terminal+=	hs-prettyprinter-ansi-terminal>=1.1.2nb2
BUILDLINK_PKGSRCDIR.hs-prettyprinter-ansi-terminal?=	../../textproc/hs-prettyprinter-ansi-terminal

.include "../../devel/hs-ansi-terminal/buildlink3.mk"
.include "../../textproc/hs-prettyprinter/buildlink3.mk"
.endif	# HS_PRETTYPRINTER_ANSI_TERMINAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-prettyprinter-ansi-terminal
