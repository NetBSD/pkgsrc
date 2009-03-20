# $NetBSD: buildlink3.mk,v 1.14 2009/03/20 19:24:25 joerg Exp $

BUILDLINK_TREE+=	ogre

.if !defined(OGRE_BUILDLINK3_MK)
OGRE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ogre+=	ogre>=0.12.1nb1
BUILDLINK_ABI_DEPENDS.ogre+=	ogre>=0.12.1nb8
BUILDLINK_PKGSRCDIR.ogre?=	../../devel/ogre

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/devIL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.endif # OGRE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ogre
