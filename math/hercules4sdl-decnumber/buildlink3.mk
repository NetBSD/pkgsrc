# $NetBSD: buildlink3.mk,v 1.1 2021/11/06 16:40:06 rhialto Exp $

BUILDLINK_TREE+=	hercules4sdl-decnumber

.if !defined(HERCULES4SDL_DECNUMBER_BUILDLINK3_MK)
HERCULES4SDL_DECNUMBER_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hercules4sdl-decnumber?=	build

BUILDLINK_API_DEPENDS.hercules4sdl-decnumber+=	hercules4sdl-decnumber>=3.68.0
BUILDLINK_PKGSRCDIR.hercules4sdl-decnumber?=	../../math/hercules4sdl-decnumber
.endif	# HERCULES4SDL_DECNUMBER_BUILDLINK3_MK

BUILDLINK_TREE+=	-hercules4sdl-decnumber
