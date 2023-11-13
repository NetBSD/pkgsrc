# $NetBSD: buildlink3.mk,v 1.1 2023/11/13 18:11:19 wiz Exp $

BUILDLINK_TREE+=	libgnome-games-support1

.if !defined(LIBGNOME_GAMES_SUPPORT1_BUILDLINK3_MK)
LIBGNOME_GAMES_SUPPORT1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgnome-games-support1+=	libgnome-games-support1>=1.8.2
BUILDLINK_PKGSRCDIR.libgnome-games-support1?=	../../games/libgnome-games-support1

.include "../../devel/libgee/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# LIBGNOME_GAMES_SUPPORT1_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgnome-games-support1
