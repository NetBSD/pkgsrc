# $NetBSD: buildlink3.mk,v 1.1 2021/11/06 16:42:37 rhialto Exp $

BUILDLINK_TREE+=	hercules4sdl-crypto

.if !defined(HERCULES4SDL_CRYPTO_BUILDLINK3_MK)
HERCULES4SDL_CRYPTO_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.hercules4sdl-crypto?=	build

BUILDLINK_API_DEPENDS.hercules4sdl-crypto+=	hercules4sdl-crypto>=1.0.0
BUILDLINK_PKGSRCDIR.hercules4sdl-crypto?=	../../security/hercules4sdl-crypto
.endif	# HERCULES4SDL_CRYPTO_BUILDLINK3_MK

BUILDLINK_TREE+=	-hercules4sdl-crypto
