# $NetBSD: buildlink2.mk,v 1.2 2002/09/20 22:44:19 jlam Exp $

.if !defined(PYTHON20_BUILDLINK2_MK)
PYTHON20_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_PACKAGES+=		python20
BUILDLINK_DEPENDS.python20?=	python20>=2.0
BUILDLINK_PKGSRCDIR.python20?=	../../lang/python20

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python20?=	${BUILDLINK_DEPMETHOD.python}
.endif

EVAL_PREFIX+=	BUILDLINK_PREFIX.python20=python20
BUILDLINK_PREFIX.python20_DEFAULT=	${LOCALBASE}
BUILDLINK_FILES.python20!= \
	${GREP} "^include/" ${.CURDIR}/${BUILDLINK_PKGSRCDIR.python20}/PLIST
BUILDLINK_FILES.python20+=	lib/python2.0/config/libpython2.0.*

BUILDLINK_TARGETS+=	python20-buildlink

python20-buildlink: _BUILDLINK_USE

.endif	# PYTHON20_BUILDLINK2_MK
