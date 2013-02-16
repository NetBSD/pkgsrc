# $NetBSD: buildlink3.mk,v 1.35 2013/02/16 11:19:34 wiz Exp $

BUILDLINK_TREE+=	kdegames

.if !defined(KDEGAMES_BUILDLINK3_MK)
KDEGAMES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdegames+=	kdegames>=3.5.0nb1
BUILDLINK_ABI_DEPENDS.kdegames+=	kdegames>=3.5.10nb20
BUILDLINK_PKGSRCDIR.kdegames?=	../../games/kdegames3

.include "../../x11/kdebase3/buildlink3.mk"
.include "../../x11/kdelibs3/buildlink3.mk"
.endif # KDEGAMES_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdegames
