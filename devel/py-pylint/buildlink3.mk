# $NetBSD: buildlink3.mk,v 1.1 2014/03/12 01:26:03 rodent Exp $

BUILDLINK_TREE+=	pylint

.if !defined(PYLINT_BUILDLINK3_MK)
PYLINT_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.pylint+=	${PYPKGPREFIX}-pylint>=0.22.0
BUILDLINK_PKGSRCDIR.pylint?=	../../devel/py-pylint
.endif	# PYLINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-pylint
