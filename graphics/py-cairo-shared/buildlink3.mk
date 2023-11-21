# $NetBSD: buildlink3.mk,v 1.1 2023/11/21 19:56:37 markd Exp $

BUILDLINK_TREE+=	py-cairo-shared

.if !defined(PY_CAIRO_SHARED_BUILDLINK3_MK)
PY_CAIRO_SHARED_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-cairo-shared+=	py-cairo-shared>=1.25.1
BUILDLINK_PKGSRCDIR.py-cairo-shared?=	../../graphics/py-cairo-shared
.endif	# PY_CAIRO_SHARED_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-cairo-shared
