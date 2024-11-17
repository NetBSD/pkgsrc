# $NetBSD: buildlink3.mk,v 1.6 2024/11/17 07:15:57 wiz Exp $

BUILDLINK_TREE+=	libgnome-games-support1

.if !defined(LIBGNOME_GAMES_SUPPORT1_BUILDLINK3_MK)
LIBGNOME_GAMES_SUPPORT1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgnome-games-support1+=	libgnome-games-support1>=1.8.2
BUILDLINK_ABI_DEPENDS.libgnome-games-support1?=	libgnome-games-support1>=1.8.2nb5
BUILDLINK_PKGSRCDIR.libgnome-games-support1?=	../../games/libgnome-games-support1

.include "../../devel/libgee/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# LIBGNOME_GAMES_SUPPORT1_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgnome-games-support1
