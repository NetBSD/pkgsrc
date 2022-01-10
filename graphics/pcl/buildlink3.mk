# $NetBSD: buildlink3.mk,v 1.7 2022/01/10 01:46:35 ryoon Exp $

BUILDLINK_TREE+=	pcl

.if !defined(PCL_BUILDLINK3_MK)
PCL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pcl+=	pcl>=1.10.0
BUILDLINK_ABI_DEPENDS.pcl+=	pcl>=1.11.1nb6
BUILDLINK_PKGSRCDIR.pcl?=	../../graphics/pcl

.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../math/flann-lib/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../math/qhull/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
# Not used correctly right now, see
# https://github.com/PointCloudLibrary/pcl/issues/4744
#.include "../../devel/metslib/buildlink3.mk"

pkgbase := pcl
.include "../../mk/pkg-build-options.mk"

.if ${PKG_BUILD_OPTIONS.pcl:Mvtk}
.include "../../graphics/vtk/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.endif

.endif # PCL_BUILDLINK3_MK

BUILDLINK_TREE+=	-pcl
