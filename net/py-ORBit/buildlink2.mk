# $NetBSD: buildlink2.mk,v 1.6 2003/11/12 01:31:51 salo Exp $

.if !defined(PYORBIT_BUILDLINK2_MK)
PYORBIT_BUILDLINK2_MK=	# defined

PYTHON_VERSIONS_ACCEPTED=	23pth 22pth
.include "../../lang/python/pyversion.mk"

BUILDLINK_PACKAGES+=			pyorbit
BUILDLINK_DEPENDS.pyorbit?=		${PYPKGPREFIX}-ORBit>=2.0.0nb1
BUILDLINK_PKGSRCDIR.pyorbit?=		../../net/py-ORBit

EVAL_PREFIX+=	BUILDLINK_PREFIX.pyorbit=${PYPKGPREFIX}-ORBit
BUILDLINK_PREFIX.pyorbit_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.pyorbit+=	include/pyorbit-2/pyorbit.h
BUILDLINK_FILES.pyorbit+=	lib/pkgconfig/pyorbit-2.pc

.include "../../net/ORBit2/buildlink2.mk"

BUILDLINK_TARGETS+=	pyorbit-buildlink

pyorbit-buildlink: _BUILDLINK_USE

.endif	# PYORBIT_BUILDLINK2_MK
