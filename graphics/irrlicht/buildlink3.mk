# $NetBSD: buildlink3.mk,v 1.1 2019/06/30 22:13:13 nia Exp $

BUILDLINK_TREE+=	irrlicht

.if !defined(IRRLICHT_BUILDLINK3_MK)
IRRLICHT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.irrlicht+=	irrlicht>=1.8
BUILDLINK_PKGSRCDIR.irrlicht?=		../../graphics/irrlicht

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.endif	# IRRLICHT_BUILDLINK3_MK

BUILDLINK_TREE+=	-irrlicht
