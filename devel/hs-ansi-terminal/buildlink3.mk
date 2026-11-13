# $NetBSD: buildlink3.mk,v 1.24 2026/11/13 14:38:46 pho Exp $

BUILDLINK_TREE+=	hs-ansi-terminal

.if !defined(HS_ANSI_TERMINAL_BUILDLINK3_MK)
HS_ANSI_TERMINAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ansi-terminal+=	hs-ansi-terminal>=1.1.2
BUILDLINK_ABI_DEPENDS.hs-ansi-terminal+=	hs-ansi-terminal>=1.1.2nb4
BUILDLINK_PKGSRCDIR.hs-ansi-terminal?=		../../devel/hs-ansi-terminal

.include "../../devel/hs-ansi-terminal-types/buildlink3.mk"
.include "../../devel/hs-colour/buildlink3.mk"
.endif	# HS_ANSI_TERMINAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ansi-terminal
