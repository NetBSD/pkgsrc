# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/08/04 08:25:23 drochner Exp $

.if !defined(PYTHON23_BUILDLINK2_MK)
PYTHON23_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_PACKAGES+=		python23
BUILDLINK_PKGBASE.python23?=	python23
BUILDLINK_DEPENDS.python23?=	python23>=2.3
BUILDLINK_PKGSRCDIR.python23?=	../../lang/python23

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python23?=	${BUILDLINK_DEPMETHOD.python}
.endif

EVAL_PREFIX+=	BUILDLINK_PREFIX.python23=python23
BUILDLINK_PREFIX.python23_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES_CMD.python23= \
	${BUILDLINK_PLIST_CMD.python23} |				\
		${GREP} '^\(include\|lib.*/lib[^/]*$$\)'
BUILDLINK_TRANSFORM+=		l:python:python2.3

BUILDLINK_CPPFLAGS.python23+= \
	-I${BUILDLINK_PREFIX.python23}/include/python2.3
BUILDLINK_LDFLAGS.python23+= \
	-L${BUILDLINK_PREFIX.python23}/lib/python2.3/config		\
	-Wl,-R${BUILDLINK_PREFIX.python23}/lib/python2.3/config

BUILDLINK_TARGETS+=	python23-buildlink

python23-buildlink: _BUILDLINK_USE

.endif	# PYTHON23_BUILDLINK2_MK
