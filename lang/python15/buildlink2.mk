# $NetBSD: buildlink2.mk,v 1.3 2002/10/09 11:40:40 jlam Exp $

.if !defined(PYTHON15_BUILDLINK2_MK)
PYTHON15_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_PACKAGES+=		python15
BUILDLINK_DEPENDS.python15?=	python15>=1.5
BUILDLINK_PKGSRCDIR.python15?=	../../lang/python15

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python15?=	${BUILDLINK_DEPMETHOD.python}
.endif

EVAL_PREFIX+=	BUILDLINK_PREFIX.python15=python15
BUILDLINK_PREFIX.python15_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.python15!= \
	${GREP} "^include/" ${.CURDIR}/${BUILDLINK_PKGSRCDIR.python15}/PLIST
BUILDLINK_FILES.python15+=	lib/python1.5/config/libpython1.5.*
BUILDLINK_TRANSFORM+=		l:python:python1.5

BUILDLINK_CPPFLAGS.python15+= \
	-I${BUILDLINK_PREFIX.python15}/include/python1.5
BUILDLINK_LDFLAGS.python15+= \
	-L${BUILDLINK_PREFIX.python15}/lib/python1.5/config		\
	-Wl,-R${BUILDLINK_PREFIX.python15}/lib/python1.5/config

BUILDLINK_TARGETS+=	python15-buildlink

python15-buildlink: _BUILDLINK_USE

.endif	# PYTHON15_BUILDLINK2_MK
