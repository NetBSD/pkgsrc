# $NetBSD: buildlink3.mk,v 1.2 2026/11/25 14:42:13 wiz Exp $

BUILDLINK_TREE+=	irrlicht

.if !defined(IRRLICHT_BUILDLINK3_MK)
IRRLICHT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.irrlicht+=	irrlicht>=1.8
BUILDLINK_PKGSRCDIR.irrlicht?=		../../graphics/irrlicht

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/mesa.buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.endif	# IRRLICHT_BUILDLINK3_MK

BUILDLINK_TREE+=	-irrlicht
