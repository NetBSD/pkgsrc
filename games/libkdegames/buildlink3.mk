# $NetBSD: buildlink3.mk,v 1.26 2023/05/22 20:59:59 wiz Exp $

BUILDLINK_TREE+=	libkdegames

.if !defined(LIBKDEGAMES_BUILDLINK3_MK)
LIBKDEGAMES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkdegames+=	libkdegames>=19.08.3
BUILDLINK_ABI_DEPENDS.libkdegames?=	libkdegames>=22.08.1nb6
BUILDLINK_PKGSRCDIR.libkdegames?=	../../games/libkdegames

.include "../../devel/kdeclarative/buildlink3.mk"
.include "../../net/kdnssd/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# LIBKDEGAMES_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkdegames
