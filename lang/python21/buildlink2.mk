# $NetBSD: buildlink2.mk,v 1.1 2002/09/20 22:33:31 jlam Exp $

.if !defined(PYTHON21_BUILDLINK2_MK)
PYTHON21_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		python21
BUILDLINK_DEPENDS.python21?=	python21>=2.1
BUILDLINK_PKGSRCDIR.python21?=	../../lang/python21

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python21?=	${BUILDLINK_DEPMETHOD.python}
.endif

EVAL_PREFIX+=	BUILDLINK_PREFIX.python21=python21
BUILDLINK_PREFIX.python21_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.python21=	include/python2.1/*
BUILDLINK_FILES.python21+=	lib/python2.1/config/libpython2.1.*

BUILDLINK_TARGETS+=	python21-buildlink

python21-buildlink: _BUILDLINK_USE

.endif	# PYTHON21_BUILDLINK2_MK
