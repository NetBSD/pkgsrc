# $NetBSD: buildlink3.mk,v 1.4 2018/01/07 13:04:03 rillig Exp $

BUILDLINK_TREE+=	hs-ansi-terminal

.if !defined(HS_ANSI_TERMINAL_BUILDLINK3_MK)
HS_ANSI_TERMINAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ansi-terminal+=	hs-ansi-terminal>=0.6.2
BUILDLINK_ABI_DEPENDS.hs-ansi-terminal+=	hs-ansi-terminal>=0.6.2.1
BUILDLINK_PKGSRCDIR.hs-ansi-terminal?=		../../devel/hs-ansi-terminal
.endif	# HS_ANSI_TERMINAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ansi-terminal
