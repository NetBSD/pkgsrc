# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:24 joerg Exp $

BUILDLINK_TREE+=	netcdf

.if !defined(NETCDF_BUILDLINK3_MK)
NETCDF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.netcdf+=	netcdf>=3.5
BUILDLINK_ABI_DEPENDS.netcdf+=	netcdf>=3.5.0nb2
BUILDLINK_PKGSRCDIR.netcdf?=	../../devel/netcdf
.endif # NETCDF_BUILDLINK3_MK

BUILDLINK_TREE+=	-netcdf
