# $NetBSD: buildlink3.mk,v 1.1 2021/11/06 16:42:10 rhialto Exp $

BUILDLINK_TREE+=	hercules4sdl-telnet

.if !defined(HERCULES4SDL_TELNET_BUILDLINK3_MK)
HERCULES4SDL_TELNET_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hercules4sdl-telnet?=	build

BUILDLINK_API_DEPENDS.hercules4sdl-telnet+=	hercules4sdl-telnet>=1.0.0
BUILDLINK_PKGSRCDIR.hercules4sdl-telnet?=	../../net/hercules4sdl-telnet
.endif	# HERCULES4SDL_TELNET_BUILDLINK3_MK

BUILDLINK_TREE+=	-hercules4sdl-telnet
