# $NetBSD: buildlink2.mk,v 1.1 2002/09/20 22:33:31 jlam Exp $

.if !defined(PYTHON22_BUILDLINK2_MK)
PYTHON22_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=		python22
BUILDLINK_DEPENDS.python22?=	python22>=2.2
BUILDLINK_PKGSRCDIR.python22?=	../../lang/python22

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python22?=	${BUILDLINK_DEPMETHOD.python}
.endif

EVAL_PREFIX+=	BUILDLINK_PREFIX.python22=python22
BUILDLINK_PREFIX.python22_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.python22=	include/python2.2/*
BUILDLINK_FILES.python22+=	lib/python2.2/config/libpython2.2.*

BUILDLINK_TARGETS+=	python22-buildlink

python22-buildlink: _BUILDLINK_USE

.endif	# PYTHON22_BUILDLINK2_MK
