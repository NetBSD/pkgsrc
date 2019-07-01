# $NetBSD: buildlink3.mk,v 1.20 2019/07/01 04:07:47 ryoon Exp $

BUILDLINK_TREE+=	netcdf

.if !defined(NETCDF_BUILDLINK3_MK)
NETCDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.netcdf+=	netcdf>=3.5
BUILDLINK_ABI_DEPENDS.netcdf+=	netcdf>=4.6.1nb3
BUILDLINK_PKGSRCDIR.netcdf?=	../../devel/netcdf

.include "../../devel/hdf5/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif # NETCDF_BUILDLINK3_MK

BUILDLINK_TREE+=	-netcdf
