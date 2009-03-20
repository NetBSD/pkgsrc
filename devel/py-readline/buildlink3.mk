# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:28 joerg Exp $

BUILDLINK_TREE+=	pyreadline

.if !defined(PYREADLINE_BUILDLINK3_MK)
PYREADLINE_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pyreadline+=		${PYPKGPREFIX}-readline-[0-9]*
BUILDLINK_ABI_DEPENDS.pyreadline?=	${PYPKGPREFIX}-readline>=0nb2
BUILDLINK_PKGSRCDIR.pyreadline?=	../../devel/py-readline
.endif # PYREADLINE_BUILDLINK3_MK

BUILDLINK_TREE+=	-pyreadline
