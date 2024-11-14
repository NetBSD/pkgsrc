# $NetBSD: buildlink3.mk,v 1.29 2024/11/14 22:19:33 wiz Exp $

BUILDLINK_TREE+=	netcdf-cxx

.if !defined(NETCDF_CXX_BUILDLINK3_MK)
NETCDF_CXX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.netcdf-cxx+=	netcdf-cxx>=4.2
BUILDLINK_ABI_DEPENDS.netcdf-cxx+=	netcdf-cxx>=4.3.1nb7
BUILDLINK_PKGSRCDIR.netcdf-cxx?=	../../devel/netcdf-cxx

.include "../../devel/netcdf/buildlink3.mk"
.endif	# NETCDF_CXX_BUILDLINK3_MK

BUILDLINK_TREE+=	-netcdf-cxx
