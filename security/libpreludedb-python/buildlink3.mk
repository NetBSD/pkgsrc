# $NetBSD: buildlink3.mk,v 1.1.1.1 2009/10/02 10:04:48 hasso Exp $

BUILDLINK_TREE+=	libpreludedb-python

.if !defined(LIBPRELUDEDB_PYTHON_BUILDLINK3_MK)
LIBPRELUDEDB_PYTHON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libpreludedb-python+=	libpreludedb-python>=0.9.15.3
BUILDLINK_PKGSRCDIR.libpreludedb-python?=	../../security/libpreludedb-python

.endif	# LIBPRELUDEDB_PYTHON_BUILDLINK3_MK

BUILDLINK_TREE+=	-libpreludedb-python
