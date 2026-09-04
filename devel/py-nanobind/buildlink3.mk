# $NetBSD: buildlink3.mk,v 1.1 2026/09/04 12:22:12 adam Exp $

BUILDLINK_TREE+=	py-nanobind

.if !defined(PY_NANOBIND_BUILDLINK3_MK)
PY_NANOBIND_BUILDLINK3_MK:=

# As this package defaults to DEPMETHOD=build we also set python to default
# to build, and avoid pulling in unwanted indirect buildlink3 dependencies.
PYTHON_FOR_BUILD_ONLY?=         yes
.include "../../lang/python/pyversion.mk"

BUILDLINK_DEPMETHOD.py-nanobind?=	build

BUILDLINK_API_DEPENDS.py-nanobind+=	${PYPKGPREFIX}-nanobind>=3.0.1
BUILDLINK_PKGSRCDIR.py-nanobind?=	../../devel/py-nanobind
.endif	# PY_NANOBIND_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-nanobind
