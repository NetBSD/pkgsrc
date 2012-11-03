# $NetBSD: buildlink3.mk,v 1.1 2012/11/03 14:18:06 imil Exp $

BUILDLINK_TREE+=	py-irclib

.if !defined(PY_IRCLIB_BUILDLINK3_MK)
PY_IRCLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-irclib+=	${PYPKGPREFIX}-irclib>=3.4.2
BUILDLINK_PKGSRCDIR.py-irclib?=	../../net/py-irclib

.endif	# PY_IRCLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-irclib
