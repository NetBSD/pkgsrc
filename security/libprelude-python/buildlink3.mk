# $NetBSD: buildlink3.mk,v 1.3 2022/06/28 11:35:36 wiz Exp $

BUILDLINK_TREE+=	libprelude-python

.if !defined(LIBPRELUDE_PYTHON_BUILDLINK3_MK)
LIBPRELUDE_PYTHON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libprelude-python+=	libprelude-python>=0.9.24
BUILDLINK_ABI_DEPENDS.libprelude-python?=		libprelude-python>=0.9.24.1nb21
BUILDLINK_PKGSRCDIR.libprelude-python?=		../../security/libprelude-python
.endif	# LIBPRELUDE_PYTHON_BUILDLINK3_MK

BUILDLINK_TREE+=	-libprelude-python
