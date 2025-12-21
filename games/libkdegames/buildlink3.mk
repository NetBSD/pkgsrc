# $NetBSD: buildlink3.mk,v 1.40 2025/12/21 11:52:08 markd Exp $

BUILDLINK_TREE+=	libkdegames

.if !defined(LIBKDEGAMES_BUILDLINK3_MK)
LIBKDEGAMES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkdegames+=	libkdegames>=25.08.2
BUILDLINK_ABI_DEPENDS.libkdegames?=	libkdegames>=25.08.2
BUILDLINK_PKGSRCDIR.libkdegames?=	../../games/libkdegames

.include "../../devel/kf6-kdeclarative/buildlink3.mk"
.include "../../net/kf6-kdnssd/buildlink3.mk"
.include "../../net/kf6-knewstuff/buildlink3.mk"
.include "../../textproc/kf6-kcompletion/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# LIBKDEGAMES_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkdegames
