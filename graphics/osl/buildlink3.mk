# $NetBSD: buildlink3.mk,v 1.1 2026/11/08 15:03:18 ryoon Exp $

BUILDLINK_TREE+=	osl

.if !defined(OSL_BUILDLINK3_MK)
OSL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.osl+=	osl>=1.15.7.0
BUILDLINK_PKGSRCDIR.osl?=	../../graphics/osl

BUILDLINK_FILES.osl+=		bin/oslc
BUILDLINK_FILES.osl+=		bin/oslinfo
BUILDLINK_FILES.osl+=		lib/osl.imageio.so

.include "../../devel/robin-map/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/imath/buildlink3.mk"
.include "../../graphics/openimageio/buildlink3.mk"
.include "../../graphics/partio/buildlink3.mk"
.include "../../textproc/pugixml/buildlink3.mk"
.include "../../lang/clang/buildlink3.mk"
.endif	# OSL_BUILDLINK3_MK

BUILDLINK_TREE+=	-osl
