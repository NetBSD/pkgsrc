# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:25:22 joerg Exp $

BUILDLINK_TREE+=	py-gnupg

.if !defined(PY_GNUPG_BUILDLINK3_MK)
PY_GNUPG_BUILDLINK3_MK:=

.  include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-gnupg+=	${PYPKGPREFIX}-gnupg-[0-9]*
BUILDLINK_ABI_DEPENDS.py-gnupg+=	${PYPKGPREFIX}-gnupg>=0.3.2
BUILDLINK_PKGSRCDIR.py-gnupg?=		../../security/py-gnupg
.endif # PY_GNUPG_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-gnupg
