# $NetBSD: buildlink3.mk,v 1.21 2019/07/20 22:46:04 wiz Exp $

BUILDLINK_TREE+=	libpreludedb

.if !defined(LIBPRELUDEDB_BUILDLINK3_MK)
LIBPRELUDEDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpreludedb+=	libpreludedb>=0.9.15.3
BUILDLINK_ABI_DEPENDS.libpreludedb+=	libpreludedb>=0.9.15.3nb14
BUILDLINK_PKGSRCDIR.libpreludedb?=	../../security/libpreludedb

.include "../../security/libprelude/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.endif	# LIBPRELUDEDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpreludedb
