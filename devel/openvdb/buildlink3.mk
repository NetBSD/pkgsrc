# $NetBSD: buildlink3.mk,v 1.1 2026/11/08 15:45:05 ryoon Exp $

BUILDLINK_TREE+=	openvdb

.if !defined(OPENVDB_BUILDLINK3_MK)
OPENVDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openvdb+=	openvdb>=13.0.0
BUILDLINK_PKGSRCDIR.openvdb?=	../../devel/openvdb

.include "../../devel/blosc/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../parallel/threadingbuildingblocks/buildlink3.mk"
.endif	# OPENVDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-openvdb
