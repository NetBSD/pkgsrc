# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:24:28 joerg Exp $

BUILDLINK_TREE+=	py-pexpect

.if !defined(PY_PEXPECT_BUILDLINK3_MK)
PY_PEXPECT_BUILDLINK3_MK:=

.  include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-pexpect+=	${PYPKGPREFIX}-pexpect>=2.1
BUILDLINK_ABI_DEPENDS.py-pexpect+=	${PYPKGPREFIX}-pexpect>=2.1
BUILDLINK_PKGSRCDIR.py-pexpect?=		../../devel/py-pexpect
.endif # PY_PEXPECT_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-pexpect
