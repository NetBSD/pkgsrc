# $NetBSD: buildlink3.mk,v 1.2 2018/01/07 13:04:27 rillig Exp $

BUILDLINK_TREE+=	py-irclib

.if !defined(PY_IRCLIB_BUILDLINK3_MK)
PY_IRCLIB_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.py-irclib+=	${PYPKGPREFIX}-irclib>=3.4.2
BUILDLINK_PKGSRCDIR.py-irclib?=		../../net/py-irclib

.endif	# PY_IRCLIB_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-irclib
