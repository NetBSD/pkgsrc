# $NetBSD: buildlink3.mk,v 1.1 2004/02/27 09:02:51 xtraeme Exp $
#
# This Makefile fragment is included by packages that use ogre.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OGRE_BUILDLINK3_MK:=	${OGRE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ogre
.endif

.if !empty(OGRE_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			ogre
BUILDLINK_DEPENDS.ogre+=		ogre>=0.12.1nb1
BUILDLINK_PKGSRCDIR.ogre?=		../../devel/ogre

.include "../../devel/devIL/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"

.endif # OGRE_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
