# $NetBSD: buildlink3.mk,v 1.28 2014/05/15 14:41:47 adam Exp $

BUILDLINK_TREE+=	ogre

.if !defined(OGRE_BUILDLINK3_MK)
OGRE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ogre+=	ogre>=1.6.3
BUILDLINK_ABI_DEPENDS.ogre+=	ogre>=1.6.3nb13
BUILDLINK_PKGSRCDIR.ogre?=	../../devel/ogre

.include "../../archivers/zziplib/buildlink3.mk"
.include "../../devel/devIL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.endif # OGRE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ogre
