# $NetBSD: buildlink2.mk,v 1.1.1.1 2002/10/25 10:48:47 drochner Exp $

.if !defined(PYTHON22_BUILDLINK2_MK)
PYTHON22_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_PACKAGES+=		python22-pth
BUILDLINK_PKGBASE.python22-pth?=	python22-pth
BUILDLINK_DEPENDS.python22-pth?=	python22-pth>=2.2
BUILDLINK_PKGSRCDIR.python22-pth?=	../../lang/python22-pth

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python22-pth?=	${BUILDLINK_DEPMETHOD.python}
.endif

EVAL_PREFIX+=	BUILDLINK_PREFIX.python22-pth=python22-pth
BUILDLINK_PREFIX.python22-pth_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES_CMD.python22-pth= \
	${BUILDLINK_PLIST_CMD.python22-pth} |				\
		${GREP} '^\(include\|lib.*/lib[^/]*$$\)'
BUILDLINK_TRANSFORM+=		l:python:python2p2

BUILDLINK_CPPFLAGS.python22-pth+= \
	-I${BUILDLINK_PREFIX.python22-pth}/include/python2p2
BUILDLINK_LDFLAGS.python22-pth+= \
	-L${BUILDLINK_PREFIX.python22-pth}/lib/python2p2/config		\
	-Wl,-R${BUILDLINK_PREFIX.python22-pth}/lib/python2p2/config

BUILDLINK_TARGETS+=	python22-pth-buildlink

python22-pth-buildlink: _BUILDLINK_USE

.endif	# PYTHON22_BUILDLINK2_MK
