# $NetBSD: buildlink2.mk,v 1.2 2002/09/20 22:44:19 jlam Exp $

.if !defined(PYTHON21_BUILDLINK2_MK)
PYTHON21_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_PACKAGES+=			python21-pth
BUILDLINK_DEPENDS.python21-pth?=	python21-pth>=2.1
BUILDLINK_PKGSRCDIR.python21-pth?=	../../lang/python21-pth

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python21-pth?=	${BUILDLINK_DEPMETHOD.python}
.endif

EVAL_PREFIX+=	BUILDLINK_PREFIX.python21-pth=python21-pth
BUILDLINK_PREFIX.python21-pth_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.python21-pth!= \
	${GREP} "^include/" ${.CURDIR}/${BUILDLINK_PKGSRCDIR.python21-pth}/PLIST
BUILDLINK_FILES.python21-pth+=	lib/python2p1/config/libpython2p1.*

BUILDLINK_TARGETS+=	python21-pth-buildlink

python21-pth-buildlink: _BUILDLINK_USE

.endif	# PYTHON21_BUILDLINK2_MK
