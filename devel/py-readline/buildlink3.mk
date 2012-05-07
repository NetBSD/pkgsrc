# $NetBSD: buildlink3.mk,v 1.8 2012/05/07 01:53:28 dholland Exp $

BUILDLINK_TREE+=	pyreadline

.if !defined(PYREADLINE_BUILDLINK3_MK)
PYREADLINE_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pyreadline+=		${PYPKGPREFIX}-readline-[0-9]*
BUILDLINK_ABI_DEPENDS.pyreadline+=	${PYPKGPREFIX}-readline>=0nb2
BUILDLINK_PKGSRCDIR.pyreadline?=	../../devel/py-readline
.endif # PYREADLINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-pyreadline
