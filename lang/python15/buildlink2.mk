# $NetBSD: buildlink2.mk,v 1.5 2002/10/12 07:28:14 jlam Exp $

.if !defined(PYTHON15_BUILDLINK2_MK)
PYTHON15_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_PACKAGES+=		python15
BUILDLINK_PKGBASE.python15?=	python15
BUILDLINK_DEPENDS.python15?=	python15>=1.5
BUILDLINK_PKGSRCDIR.python15?=	../../lang/python15

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python15?=	${BUILDLINK_DEPMETHOD.python}
.endif

EVAL_PREFIX+=	BUILDLINK_PREFIX.python15=python15
BUILDLINK_PREFIX.python15_DEFAULT=	${LOCALBASE}
_PY15_BLNK_FILES= \
	${BUILDLINK_PLIST_CMD.python15} |				\
		${EGREP} '^\(include\|lib.*/lib[^/]*$$\)'
BUILDLINK_FILES.python15=	`${_PY15_BLNK_FILES}`
BUILDLINK_TRANSFORM+=		l:python:python1.5

BUILDLINK_CPPFLAGS.python15+= \
	-I${BUILDLINK_PREFIX.python15}/include/python1.5
BUILDLINK_LDFLAGS.python15+= \
	-L${BUILDLINK_PREFIX.python15}/lib/python1.5/config		\
	-Wl,-R${BUILDLINK_PREFIX.python15}/lib/python1.5/config

BUILDLINK_TARGETS+=	python15-buildlink

python15-buildlink: _BUILDLINK_USE

.endif	# PYTHON15_BUILDLINK2_MK
