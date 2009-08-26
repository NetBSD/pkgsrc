# $NetBSD: buildlink3.mk,v 1.15 2009/08/26 19:56:44 sno Exp $

BUILDLINK_TREE+=	ogre

.if !defined(OGRE_BUILDLINK3_MK)
OGRE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ogre+=	ogre>=0.12.1nb1
BUILDLINK_ABI_DEPENDS.ogre+=	ogre>=0.12.1nb9
BUILDLINK_PKGSRCDIR.ogre?=	../../devel/ogre

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/devIL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.endif # OGRE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ogre
