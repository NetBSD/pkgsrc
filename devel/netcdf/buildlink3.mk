# $NetBSD: buildlink3.mk,v 1.32 2023/06/23 17:12:39 jperkin Exp $

BUILDLINK_TREE+=	netcdf

.if !defined(NETCDF_BUILDLINK3_MK)
NETCDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.netcdf+=	netcdf>=3.5
BUILDLINK_ABI_DEPENDS.netcdf+=	netcdf>=4.6.1nb16
BUILDLINK_PKGSRCDIR.netcdf?=	../../devel/netcdf

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif # NETCDF_BUILDLINK3_MK

BUILDLINK_TREE+=	-netcdf
