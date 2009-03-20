# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:07 joerg Exp $

BUILDLINK_TREE+=	py-sqlite2

.if !defined(PY_SQLITE2_BUILDLINK3_MK)
PY_SQLITE2_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-sqlite2+=	${PYPKGPREFIX}-sqlite2>=2.3.2
BUILDLINK_PKGSRCDIR.py-sqlite2?=	../../databases/py-sqlite2
.endif # PY_SQLITE2_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-sqlite2
