# $NetBSD: buildlink3.mk,v 1.2 2021/05/05 13:00:56 thor Exp $

BUILDLINK_TREE+=	gl2ps

.if !defined(GL2PS_BUILDLINK3_MK)
GL2PS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gl2ps+=	gl2ps>=1.4.2
BUILDLINK_PKGSRCDIR.gl2ps?=	../../graphics/gl2ps

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.endif	# GL2PS_BUILDLINK3_MK

BUILDLINK_TREE+=	-gl2ps
