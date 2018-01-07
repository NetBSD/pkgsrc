# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:03 rillig Exp $

BUILDLINK_TREE+=	hdf5-c++

.if !defined(HDF5_C++_BUILDLINK3_MK)
HDF5_C++_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hdf5-c+++=	hdf5-c++>=1.8.14
BUILDLINK_PKGSRCDIR.hdf5-c++?=		../../devel/hdf5-c++

.include "../../devel/hdf5/buildlink3.mk"
.endif	# HDF5_C++_BUILDLINK3_MK

BUILDLINK_TREE+=	-hdf5-c++
