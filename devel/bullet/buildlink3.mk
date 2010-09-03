# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/09/03 23:01:47 wiz Exp $

BUILDLINK_TREE+=	bullet

.if !defined(BULLET_BUILDLINK3_MK)
BULLET_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.bullet+=	bullet>=2.76
BUILDLINK_PKGSRCDIR.bullet?=	../../devel/bullet

#.include "../../graphics/glut/buildlink3.mk"
.endif	# BULLET_BUILDLINK3_MK

BUILDLINK_TREE+=	-bullet
