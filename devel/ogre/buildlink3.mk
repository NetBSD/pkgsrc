# $NetBSD: buildlink3.mk,v 1.32 2023/07/21 08:30:48 nia Exp $

BUILDLINK_TREE+=	ogre

.if !defined(OGRE_BUILDLINK3_MK)
OGRE_BUILDLINK3_MK:=

USE_CXX_FEATURES+=	c++11 put_time

BUILDLINK_API_DEPENDS.ogre+=	ogre>=1.12
BUILDLINK_ABI_DEPENDS.ogre+=	ogre>=1.12
BUILDLINK_PKGSRCDIR.ogre?=	../../devel/ogre

.include "../../mk/pthread.buildlink3.mk"
.endif # OGRE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ogre
