# $NetBSD: buildlink2.mk,v 1.2 2003/12/30 23:14:17 cjep Exp $
#
# This Makefile fragment is included by packages that use py-sybase.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(PY_SYBASE_BUILDLINK2_MK)
PY_SYBASE_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=		py-sybase
BUILDLINK_DEPENDS.py-sybase?=	${PYPKGPREFIX}-sybase>=0.36
BUILDLINK_PKGSRCDIR.py-sybase?=	../../databases/py-sybase

EVAL_PREFIX+=	BUILDLINK_PREFIX.py-sybase=${PYPKGPREFIX}-sybase
BUILDLINK_PREFIX.py-sybase_DEFAULT=	${LOCALBASE}
 
.include "../../databases/freetds/buildlink2.mk"

BUILDLINK_TARGETS+=	py-sybase-buildlink

py-sybase-buildlink: _BUILDLINK_USE
.endif # PY_SYBASE_BUILDLINK2_MK
