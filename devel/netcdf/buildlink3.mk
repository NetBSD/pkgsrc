# $NetBSD: buildlink3.mk,v 1.25 2020/03/08 16:47:40 wiz Exp $

BUILDLINK_TREE+=	netcdf

.if !defined(NETCDF_BUILDLINK3_MK)
NETCDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.netcdf+=	netcdf>=3.5
BUILDLINK_ABI_DEPENDS.netcdf+=	netcdf>=4.6.1nb8
BUILDLINK_PKGSRCDIR.netcdf?=	../../devel/netcdf

.include "../../devel/hdf5/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.endif # NETCDF_BUILDLINK3_MK

BUILDLINK_TREE+=	-netcdf
