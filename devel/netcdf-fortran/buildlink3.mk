# $NetBSD: buildlink3.mk,v 1.19 2020/05/06 14:04:08 adam Exp $

BUILDLINK_TREE+=	netcdf-fortran

.if !defined(NETCDF_FORTRAN_BUILDLINK3_MK)
NETCDF_FORTRAN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.netcdf-fortran+=	netcdf-fortran>=4.2
BUILDLINK_ABI_DEPENDS.netcdf-fortran?=	netcdf-fortran>=4.2nb18
BUILDLINK_PKGSRCDIR.netcdf-fortran?=	../../devel/netcdf-fortran

.include "../../devel/netcdf/buildlink3.mk"
.endif	# NETCDF_FORTRAN_BUILDLINK3_MK

BUILDLINK_TREE+=	-netcdf-fortran
