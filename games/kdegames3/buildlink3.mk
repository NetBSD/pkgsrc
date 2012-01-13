# $NetBSD: buildlink3.mk,v 1.25 2012/01/13 10:55:07 obache Exp $

BUILDLINK_TREE+=	kdegames

.if !defined(KDEGAMES_BUILDLINK3_MK)
KDEGAMES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdegames+=	kdegames>=3.5.0nb1
BUILDLINK_ABI_DEPENDS.kdegames?=	kdegames>=3.5.10nb10
BUILDLINK_PKGSRCDIR.kdegames?=	../../games/kdegames3

.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.endif # KDEGAMES_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdegames
