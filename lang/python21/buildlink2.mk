# $NetBSD: buildlink2.mk,v 1.5 2002/10/12 07:28:15 jlam Exp $

.if !defined(PYTHON21_BUILDLINK2_MK)
PYTHON21_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_PACKAGES+=		python21
BUILDLINK_PKGBASE.python21?=	python21
BUILDLINK_DEPENDS.python21?=	python21>=2.1
BUILDLINK_PKGSRCDIR.python21?=	../../lang/python21

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python21?=	${BUILDLINK_DEPMETHOD.python}
.endif

EVAL_PREFIX+=	BUILDLINK_PREFIX.python21=python21
BUILDLINK_PREFIX.python21_DEFAULT=	${LOCALBASE}
_PY21_BLNK_FILES= \
	${BUILDLINK_PLIST_CMD.python21} |				\
		${EGREP} '^\(include\|lib.*/lib[^/]*$$\)'
BUILDLINK_FILES.python21=	`${_PY21_BLNK_FILES}`
BUILDLINK_TRANSFORM+=		l:python:python2.1

BUILDLINK_CPPFLAGS.python21+= \
	-I${BUILDLINK_PREFIX.python21}/include/python2.1
BUILDLINK_LDFLAGS.python21+= \
	-L${BUILDLINK_PREFIX.python21}/lib/python2.1/config		\
	-Wl,-R${BUILDLINK_PREFIX.python21}/lib/python2.1/config

BUILDLINK_TARGETS+=	python21-buildlink

python21-buildlink: _BUILDLINK_USE

.endif	# PYTHON21_BUILDLINK2_MK
