# $NetBSD: buildlink3.mk,v 1.2 2004/03/05 19:25:11 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OGRE_BUILDLINK3_MK:=	${OGRE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ogre
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nogre}
BUILDLINK_PACKAGES+=	ogre

.if !empty(OGRE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.ogre+=	ogre>=0.12.1nb1
BUILDLINK_PKGSRCDIR.ogre?=	../../devel/ogre

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/devIL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"

.endif	# OGRE_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
