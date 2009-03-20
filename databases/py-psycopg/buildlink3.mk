# $NetBSD: buildlink3.mk,v 1.10 2009/03/20 19:24:07 joerg Exp $

BUILDLINK_TREE+=	psycopg

.if !defined(PY_PSYCOPG_BUILDLINK3_MK)
PY_PSYCOPG_BUILDLINK3_MK:=

.  include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.psycopg+=	${PYPKGPREFIX}-psycopg>=1.1.21
BUILDLINK_ABI_DEPENDS.psycopg+=	${PYPKGPREFIX}-psycopg>=1.1.21nb1
BUILDLINK_PKGSRCDIR.psycopg?=	../../databases/py-psycopg
.endif # PY_PSYCOPG_BUILDLINK3_MK

BUILDLINK_TREE+=	-psycopg
