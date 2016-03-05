# $NetBSD: buildlink3.mk,v 1.2 2016/03/05 11:27:53 jperkin Exp $

BUILDLINK_TREE+=	py-gevent

.if !defined(PY_GEVENT_BUILDLINK3_MK)
PY_GEVENT_BUILDLINK3_MK:=

.include "../../lang/python/pyversion.mk"

BUILDLINK_API_DEPENDS.py-gevent+=	${PYPKGPREFIX}-gevent>=0.13.0
BUILDLINK_ABI_DEPENDS.py-gevent?=		${PYPKGPREFIX}-gevent>=1.0.2nb1
BUILDLINK_PKGSRCDIR.py-gevent?=		../../net/py-gevent

.include "../../devel/py-cython/buildlink3.mk"
.include "../../devel/libevent/buildlink3.mk"

.endif	# PY_GEVENT_BUILDLINK3_MK

BUILDLINK_TREE+=	-py-gevent
