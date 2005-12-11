# $NetBSD: buildlink3.mk,v 1.6 2005/12/11 09:40:38 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OGRE_BUILDLINK3_MK:=	${OGRE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ogre
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nogre}
BUILDLINK_PACKAGES+=	ogre

.if !empty(OGRE_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.ogre+=	ogre>=0.12.1nb1
BUILDLINK_RECOMMENDED.ogre+=	ogre>=0.12.1nb5
BUILDLINK_PKGSRCDIR.ogre?=	../../devel/ogre
.endif	# OGRE_BUILDLINK3_MK

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/devIL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
