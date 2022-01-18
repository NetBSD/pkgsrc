# $NetBSD: buildlink3.mk,v 1.3 2022/01/18 02:48:13 pho Exp $

BUILDLINK_TREE+=	hs-terminal-size

.if !defined(HS_TERMINAL_SIZE_BUILDLINK3_MK)
HS_TERMINAL_SIZE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-terminal-size+=	hs-terminal-size>=0.3.2
BUILDLINK_ABI_DEPENDS.hs-terminal-size+=	hs-terminal-size>=0.3.2.1nb2
BUILDLINK_PKGSRCDIR.hs-terminal-size?=	../../devel/hs-terminal-size
.endif	# HS_TERMINAL_SIZE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-terminal-size
