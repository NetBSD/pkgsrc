# $NetBSD: buildlink3.mk,v 1.2 2022/06/28 11:35:37 wiz Exp $

BUILDLINK_TREE+=	libpreludedb-python

.if !defined(LIBPRELUDEDB_PYTHON_BUILDLINK3_MK)
LIBPRELUDEDB_PYTHON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpreludedb-python+=	libpreludedb-python>=0.9.15.3
BUILDLINK_ABI_DEPENDS.libpreludedb-python?=	libpreludedb-python>=0.9.15.3nb27
BUILDLINK_PKGSRCDIR.libpreludedb-python?=	../../security/libpreludedb-python

.endif	# LIBPRELUDEDB_PYTHON_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpreludedb-python
