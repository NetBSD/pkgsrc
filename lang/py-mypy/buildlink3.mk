# $NetBSD: buildlink3.mk,v 1.1 2026/02/02 18:53:01 wiz Exp $
#
# only for packages that use *.c or *.h from this package
# directly during the build

BUILDLINK_TREE+=	py-mypy

.if !defined(PY_MYPY_BUILDLINK3_MK)
PY_MYPY_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.py-mypy?=	build

BUILDLINK_API_DEPENDS.py-mypy+=	${PYPKGPREFIX}-mypy>=1.19.1nb1
BUILDLINK_PKGSRCDIR.py-mypy?=	../../lang/py-mypy

BUILDLINK_FILES.py-mypy+=	${PYSITELIB}/mypyc/lib-rt/*
BUILDLINK_FILES.py-mypy+=	${PYSITELIB}/mypyc/lib-rt/*/*
BUILDLINK_PASSTHRU_DIRS+=	${PYSITELIB}/mypyc/lib-rt
.endif	# PY_MYPY_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-mypy
