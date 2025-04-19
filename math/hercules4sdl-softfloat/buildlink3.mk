# $NetBSD: buildlink3.mk,v 1.2 2025/04/19 12:54:00 rhialto Exp $

BUILDLINK_TREE+=	hercules4sdl-softfloat

.if !defined(HERCULES4SDL_SOFTFLOAT_BUILDLINK3_MK)
HERCULES4SDL_SOFTFLOAT_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hercules4sdl-softfloat?=	build

BUILDLINK_API_DEPENDS.hercules4sdl-softfloat+=	hercules4sdl-softfloat>=3.5.0nb20250325
BUILDLINK_PKGSRCDIR.hercules4sdl-softfloat?=	../../math/hercules4sdl-softfloat
.endif	# HERCULES4SDL_SOFTFLOAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hercules4sdl-softfloat
