# $NetBSD: buildlink3.mk,v 1.3 2005/03/30 18:09:47 adam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
HDF5_BUILDLINK3_MK:=	${HDF5_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	hdf5
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nhdf5}
BUILDLINK_PACKAGES+=	hdf5

.if !empty(HDF5_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.hdf5+=	hdf5>=1.6.2
BUILDLINK_RECOMMENDED.hdf5+=	hdf5>=1.6.2nb1
BUILDLINK_PKGSRCDIR.hdf5?=	../../devel/hdf5
.endif	# HDF5_BUILDLINK3_MK

.include "../../archivers/szip/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
