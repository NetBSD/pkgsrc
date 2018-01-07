# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:29 rillig Exp $

BUILDLINK_TREE+=	libprelude-python

.if !defined(LIBPRELUDE_PYTHON_BUILDLINK3_MK)
LIBPRELUDE_PYTHON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libprelude-python+=	libprelude-python>=0.9.24
BUILDLINK_PKGSRCDIR.libprelude-python?=		../../security/libprelude-python
.endif	# LIBPRELUDE_PYTHON_BUILDLINK3_MK

BUILDLINK_TREE+=	-libprelude-python
