# $NetBSD: buildlink3.mk,v 1.1 2018/12/14 09:08:45 wiz Exp $

BUILDLINK_TREE+=	game-music-emu

.if !defined(GAME_MUSIC_EMU_BUILDLINK3_MK)
GAME_MUSIC_EMU_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.game-music-emu+=	game-music-emu>=0.6.2
BUILDLINK_PKGSRCDIR.game-music-emu?=	../../audio/game-music-emu
.endif	# GAME_MUSIC_EMU_BUILDLINK3_MK

BUILDLINK_TREE+=	-game-music-emu
