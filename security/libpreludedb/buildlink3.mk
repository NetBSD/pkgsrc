# $NetBSD: buildlink3.mk,v 1.12 2009/03/20 19:25:19 joerg Exp $

BUILDLINK_TREE+=	libpreludedb

.if !defined(LIBPRELUDEDB_BUILDLINK3_MK)
LIBPRELUDEDB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpreludedb+=	libpreludedb>=0.9.3
BUILDLINK_ABI_DEPENDS.libpreludedb?=	libpreludedb>=0.9.13nb2
BUILDLINK_PKGSRCDIR.libpreludedb?=	../../security/libpreludedb

.include "../../security/libprelude/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.endif # LIBPRELUDEDB_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpreludedb
