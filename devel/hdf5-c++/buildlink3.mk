# $NetBSD: buildlink3.mk,v 1.1 2015/08/21 16:42:25 gdt Exp $

BUILDLINK_TREE+=	hdf5-c++

.if !defined(HDF5_C++_BUILDLINK3_MK)
HDF5_C++_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hdf5-c+++=	hdf5-c++>=1.8.14
BUILDLINK_PKGSRCDIR.hdf5-c++?=	../../devel/hdf5-c++

.include "../../devel/hdf5/buildlink3.mk"
.endif	# HDF5_C++_BUILDLINK3_MK

BUILDLINK_TREE+=	-hdf5-c++
