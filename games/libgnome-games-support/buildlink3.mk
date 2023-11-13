# $NetBSD: buildlink3.mk,v 1.1 2023/11/13 17:38:38 wiz Exp $

BUILDLINK_TREE+=	libgnome-games-support

.if !defined(LIBGNOME_GAMES_SUPPORT_BUILDLINK3_MK)
LIBGNOME_GAMES_SUPPORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgnome-games-support+=	libgnome-games-support>=2.0.0
BUILDLINK_PKGSRCDIR.libgnome-games-support?=	../../games/libgnome-games-support

.include "../../devel/libgee/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.endif	# LIBGNOME_GAMES_SUPPORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgnome-games-support
