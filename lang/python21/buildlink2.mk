# $NetBSD: buildlink2.mk,v 1.9 2004/01/29 10:33:51 grant Exp $

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
BUILDLINK_FILES_CMD.python21= \
	${BUILDLINK_PLIST_CMD.python21} |				\
		${EGREP} '^(include|lib.*/lib[^/]*$$)'
BUILDLINK_TRANSFORM+=		l:python:python2.1

BUILDLINK_CPPFLAGS.python21+= \
	-I${BUILDLINK_PREFIX.python21}/include/python2.1
BUILDLINK_LDFLAGS.python21+= \
	-L${BUILDLINK_PREFIX.python21}/lib/python2.1/config		\
	-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.python21}/lib/python2.1/config
FIX_RPATH+=	BUILDLINK_LDFLAGS.python21

BUILDLINK_TARGETS+=	python21-buildlink

python21-buildlink: _BUILDLINK_USE

.endif	# PYTHON21_BUILDLINK2_MK
