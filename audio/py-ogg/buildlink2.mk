# $NetBSD: buildlink2.mk,v 1.1.1.1 2004/02/15 01:49:15 minskim Exp $

.if !defined(PYOGG_BUILDLINK2_MK)
PYOGG_BUILDLINK2_MK=	# defined

.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			pyogg
BUILDLINK_DEPENDS.pyogg?=		${PYPKGPREFIX}-pyogg>=1.3
BUILDLINK_PKGSRCDIR.pyogg?=		../../wip/py-ogg

EVAL_PREFIX+=	BUILDLINK_PREFIX.pyogg=${PYPKGPREFIX}-pyogg
BUILDLINK_PREFIX.pyogg_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pyogg+=		${PYINC}/pyogg/pyogg.h

.include "../../audio/libogg/buildlink2.mk"

BUILDLINK_TARGETS+=	pyogg-buildlink

pyogg-buildlink: _BUILDLINK_USE

.endif	# PYOGG_BUILDLINK2_MK
