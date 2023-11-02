# $NetBSD: buildlink3.mk,v 1.2 2023/11/02 06:36:17 pho Exp $

BUILDLINK_TREE+=	hs-ansi-terminal-types

.if !defined(HS_ANSI_TERMINAL_TYPES_BUILDLINK3_MK)
HS_ANSI_TERMINAL_TYPES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ansi-terminal-types+=	hs-ansi-terminal-types>=0.11.5
BUILDLINK_ABI_DEPENDS.hs-ansi-terminal-types+=	hs-ansi-terminal-types>=0.11.5nb1
BUILDLINK_PKGSRCDIR.hs-ansi-terminal-types?=	../../devel/hs-ansi-terminal-types

.include "../../devel/hs-colour/buildlink3.mk"
.endif	# HS_ANSI_TERMINAL_TYPES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ansi-terminal-types
