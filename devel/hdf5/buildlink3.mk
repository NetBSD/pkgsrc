# $NetBSD: buildlink3.mk,v 1.11 2007/05/30 08:54:29 rillig Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
HDF5_BUILDLINK3_MK:=	${HDF5_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	hdf5
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nhdf5}
BUILDLINK_PACKAGES+=	hdf5
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}hdf5

.if !empty(HDF5_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.hdf5+=	hdf5>=1.6.2
BUILDLINK_ABI_DEPENDS.hdf5+=	hdf5>=1.6.5nb1
BUILDLINK_PKGSRCDIR.hdf5?=	../../devel/hdf5
.endif	# HDF5_BUILDLINK3_MK

pkgbase := hdf5
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.hdf5:Mszip)
.include "../../archivers/szip/buildlink3.mk"
.endif

.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
