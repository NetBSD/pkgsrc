# $NetBSD: buildlink2.mk,v 1.12 2004/01/29 10:33:51 grant Exp $

.if !defined(PYTHON22_BUILDLINK2_MK)
PYTHON22_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_PACKAGES+=		python22
BUILDLINK_PKGBASE.python22?=	python22
BUILDLINK_DEPENDS.python22?=	python22>=2.2
BUILDLINK_PKGSRCDIR.python22?=	../../lang/python22

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python22?=	${BUILDLINK_DEPMETHOD.python}
.endif

EVAL_PREFIX+=	BUILDLINK_PREFIX.python22=python22
BUILDLINK_PREFIX.python22_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES_CMD.python22= \
	${BUILDLINK_PLIST_CMD.python22} |				\
		${EGREP} '^(include|lib.*/lib[^/]*$$)'
BUILDLINK_TRANSFORM+=		l:python:python2.2

BUILDLINK_CPPFLAGS.python22+= \
	-I${BUILDLINK_PREFIX.python22}/include/python2.2
BUILDLINK_LDFLAGS.python22+= \
	-L${BUILDLINK_PREFIX.python22}/lib/python2.2/config		\
	-Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.python22}/lib/python2.2/config
FIX_RPATH+=	BUILDLINK_LDFLAGS.python22

BUILDLINK_TARGETS+=	python22-buildlink

python22-buildlink: _BUILDLINK_USE

.endif	# PYTHON22_BUILDLINK2_MK
