# $NetBSD: buildlink3.mk,v 1.1.1.1 2010/08/26 13:08:48 adam Exp $

BUILDLINK_TREE+=	osg

.if !defined(OSG_BUILDLINK3_MK)
OSG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.osg+=	osg>=2.8.3
BUILDLINK_PKGSRCDIR.osg?=	../../graphics/osg

.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/openexr/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../multimedia/xine-lib/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.endif	# OSG_BUILDLINK3_MK

BUILDLINK_TREE+=	-osg
