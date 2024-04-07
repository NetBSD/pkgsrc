# $NetBSD: buildlink3.mk,v 1.3 2024/04/07 07:34:03 wiz Exp $

BUILDLINK_TREE+=	libgnome-games-support

.if !defined(LIBGNOME_GAMES_SUPPORT_BUILDLINK3_MK)
LIBGNOME_GAMES_SUPPORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgnome-games-support+=	libgnome-games-support>=2.0.0
BUILDLINK_ABI_DEPENDS.libgnome-games-support?=	libgnome-games-support>=2.0.0nb2
BUILDLINK_PKGSRCDIR.libgnome-games-support?=	../../games/libgnome-games-support

.include "../../devel/libgee/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.endif	# LIBGNOME_GAMES_SUPPORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgnome-games-support
