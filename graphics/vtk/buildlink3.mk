# $NetBSD: buildlink3.mk,v 1.7 2022/06/26 16:42:57 thor Exp $

BUILDLINK_TREE+=	vtk

.if !defined(VTK_BUILDLINK3_MK)
VTK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.vtk+=	vtk>=9.0.1
BUILDLINK_ABI_DEPENDS.vtk+=	vtk>=9.0.3nb4
BUILDLINK_PKGSRCDIR.vtk?=	../../graphics/vtk

.include "../../archivers/lz4/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/netcdf-cxx/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gl2ps/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../math/double-conversion/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../print/libharu/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../textproc/jsoncpp/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/pugixml/buildlink3.mk"

pkgbase := vtk
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.vtk:Mqt}
.  include "../../x11/qt5-qtbase/buildlink3.mk"
.endif

# Referenced in the CMake stuff and needs to be linked with it.
BUILDLINK_FILES.vtk+=	bin/vtkProbeOpenGLVersion-9.0

.endif	# VTK_BUILDLINK3_MK

BUILDLINK_TREE+=	-vtk
