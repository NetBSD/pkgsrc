# $NetBSD: buildlink2.mk,v 1.2 2002/09/20 22:44:20 jlam Exp $

.if !defined(PYTHON21_BUILDLINK2_MK)
PYTHON21_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_PACKAGES+=		python21
BUILDLINK_DEPENDS.python21?=	python21>=2.1
BUILDLINK_PKGSRCDIR.python21?=	../../lang/python21

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python21?=	${BUILDLINK_DEPMETHOD.python}
.endif

EVAL_PREFIX+=	BUILDLINK_PREFIX.python21=python21
BUILDLINK_PREFIX.python21_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.python21!= \
	${GREP} "^include/" ${.CURDIR}/${BUILDLINK_PKGSRCDIR.python21}/PLIST
BUILDLINK_FILES.python21+=	lib/python2.1/config/libpython2.1.*

BUILDLINK_TARGETS+=	python21-buildlink

python21-buildlink: _BUILDLINK_USE

.endif	# PYTHON21_BUILDLINK2_MK
