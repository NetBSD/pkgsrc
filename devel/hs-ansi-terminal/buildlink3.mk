# $NetBSD: buildlink3.mk,v 1.3 2014/11/06 13:00:44 szptvlfn Exp $

BUILDLINK_TREE+=	hs-ansi-terminal

.if !defined(HS_ANSI_TERMINAL_BUILDLINK3_MK)
HS_ANSI_TERMINAL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ansi-terminal+=	hs-ansi-terminal>=0.6.2
BUILDLINK_ABI_DEPENDS.hs-ansi-terminal+=	hs-ansi-terminal>=0.6.2.1
BUILDLINK_PKGSRCDIR.hs-ansi-terminal?=	../../devel/hs-ansi-terminal
.endif	# HS_ANSI_TERMINAL_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ansi-terminal
