# $NetBSD: buildlink3.mk,v 1.1 2015/11/16 01:46:20 khorben Exp $

BUILDLINK_TREE+=	py-pygraphviz

.if !defined(PY_PYGRAPHVIZ_BUILDLINK3_MK)
PY_PYGRAPHVIZ_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-pygraphviz+=	${PYPKGPREFIX}-pygraphviz>=1.0
BUILDLINK_PKGSRCDIR.py-pygraphviz?=	../../graphics/py-pygraphviz

.endif	# PY_PYGRAPHVIZ_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-pygraphviz
