# $NetBSD: buildlink2.mk,v 1.3 2004/03/29 05:05:39 jlam Exp $

.if !defined(PY_SUBVERSION_BUILDLINK2_MK)
PY_SUBVERSION_BUILDLINK2_MK=		#defined

BUILDLINK_PACKAGES+=			py-subversion
BUILDLINK_PKGBASE.py-subversion?=	${PYPKGPREFIX}-subversion
BUILDLINK_DEPENDS.py-subversion?=	${PYPKGPREFIX}-subversion-${SVNVER}:../../devel/py-subversion
BUILDLINK_RECOMMENDED.py-subversion?=	${PYPKGPREFIX}-subversion>=1.0.0nb1
BUILDLINK_PKGSRCDIR.py-subversion?=	../../devel/py-subversion

EVAL_PREFIX+=		BUILDLINK_PREFIX.py-subversion=py-subversion
BUILDLINK_PREFIX.py-subversion_DEFAULT=	${LOCALBASE}

.include "../../devel/subversion/buildlink2.mk"
.include "../../devel/swig-python/buildlink2.mk"
.include "../../lang/python/pyversion.mk"

.include "../../devel/subversion/Makefile.version"

BUILDLINK_TARGETS+=		py-subversion-buildlink

py-subversion-buildlink: _BUILDLINK_USE

.endif	# PY_SUBVERSION_BUILDLINK2_MK
