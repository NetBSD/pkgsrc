# $NetBSD: buildlink2.mk,v 1.1 2002/09/20 22:33:29 jlam Exp $

.if !defined(PYTHON15_BUILDLINK2_MK)
PYTHON15_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		python15
BUILDLINK_DEPENDS.python15?=	python15>=1.5
BUILDLINK_PKGSRCDIR.python15?=	../../lang/python15

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python15?=	${BUILDLINK_DEPMETHOD.python}
.endif

EVAL_PREFIX+=	BUILDLINK_PREFIX.python15=python15
BUILDLINK_PREFIX.python15_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.python15=	include/python1.5/*
BUILDLINK_FILES.python15+=	lib/python1.5/config/libpython1.5.*

BUILDLINK_TARGETS+=	python15-buildlink

python15-buildlink: _BUILDLINK_USE

.endif	# PYTHON15_BUILDLINK2_MK
