# $NetBSD: buildlink2.mk,v 1.9 2003/03/14 19:37:44 jlam Exp $

.if !defined(PYTHON20_BUILDLINK2_MK)
PYTHON20_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_PACKAGES+=		python20
BUILDLINK_PKGBASE.python20?=	python20
BUILDLINK_DEPENDS.python20?=	python20>=2.0
BUILDLINK_PKGSRCDIR.python20?=	../../lang/python20

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python20?=	${BUILDLINK_DEPMETHOD.python}
.endif

EVAL_PREFIX+=	BUILDLINK_PREFIX.python20=python20
BUILDLINK_PREFIX.python20_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES_CMD.python20= \
	${BUILDLINK_PLIST_CMD.python20} |				\
		${GREP} '^\(include\|lib.*/lib[^/]*$$\)'
BUILDLINK_TRANSFORM+=		l:python:python2.0

BUILDLINK_CPPFLAGS.python20+= \
	-I${BUILDLINK_PREFIX.python20}/include/python2.0
BUILDLINK_LDFLAGS.python20+= \
	-L${BUILDLINK_PREFIX.python20}/lib/python2.0/config		\
	-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.python20}/lib/python2.0/config
FIX_RPATH+=	BUILDLINK_LDFLAGS.python20

BUILDLINK_TARGETS+=	python20-buildlink

python20-buildlink: _BUILDLINK_USE

.endif	# PYTHON20_BUILDLINK2_MK
