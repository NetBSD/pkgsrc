# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/05/25 09:09:40 epg Exp $

.if !defined(SUBVERSION_PYTHON_BUILDLINK2_MK)
SUBVERSION_PYTHON_BUILDLINK2_MK=		#defined

BUILDLINK_PACKAGES+=			subversion-python
BUILDLINK_DEPENDS.subversion-python?=	${PYPKGPREFIX}-subversion-${SVNVER}:../../devel/subversion-python
BUILDLINK_PKGSRCDIR.subversion-python?=	../../devel/subversion-python

EVAL_PREFIX+=		BUILDLINK_PREFIX.subversion-python=subversion-python
BUILDLINK_PREFIX.subversion-python_DEFAULT=	${LOCALBASE}

.include "../../devel/subversion/buildlink2.mk"
.include "../../devel/swig-python/buildlink2.mk"
.include "../../lang/python/pyversion.mk"

.include "../../devel/subversion/Makefile.version"

BUILDLINK_TARGETS+=		subversion-python-buildlink

subversion-python-buildlink: _BUILDLINK_USE

.endif	# SUBVERSION_PYTHON_BUILDLINK2_MK
