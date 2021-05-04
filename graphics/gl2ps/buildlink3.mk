# $NetBSD: buildlink3.mk,v 1.1 2021/05/04 14:05:44 prlw1 Exp $

BUILDLINK_TREE+=	gl2ps

.if !defined(GL2PS_BUILDLINK3_MK)
GL2PS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gl2ps+=	gl2ps>=1.4.2
BUILDLINK_PKGSRCDIR.gl2ps?=	../../graphics/gl2ps

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.endif	# GL2PS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gl2ps
