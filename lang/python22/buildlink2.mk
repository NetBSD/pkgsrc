# $NetBSD: buildlink2.mk,v 1.3 2002/10/09 10:55:06 jlam Exp $

.if !defined(PYTHON22_BUILDLINK2_MK)
PYTHON22_BUILDLINK2_MK=	# defined

.include "../../mk/bsd.prefs.mk"

BUILDLINK_PACKAGES+=		python22
BUILDLINK_DEPENDS.python22?=	python22>=2.2
BUILDLINK_PKGSRCDIR.python22?=	../../lang/python22

.if defined(BUILDLINK_DEPMETHOD.python)
BUILDLINK_DEPMETHOD.python22?=	${BUILDLINK_DEPMETHOD.python}
.endif

EVAL_PREFIX+=	BUILDLINK_PREFIX.python22=python22
BUILDLINK_PREFIX.python22_DEFAULT=	${LOCALBASE}
_PY22_PLIST=	${.CURDIR}/${BUILDLINK_PKGSRCDIR.python22}/PLIST.common
_PY22_PLIST+=	${.CURDIR}/${BUILDLINK_PKGSRCDIR.python22}/PLIST.${LOWER_OPSYS}
_PY22_PLIST+=	${.CURDIR}/${BUILDLINK_PKGSRCDIR.python22}/PLIST.common_end
BUILDLINK_FILES.python22!=	${CAT} ${_PY22_PLIST} | ${GREP} "^include/"
BUILDLINK_FILES.python22+=	lib/python2.2/config/libpython2.2.*

BUILDLINK_TARGETS+=	python22-buildlink

python22-buildlink: _BUILDLINK_USE

.endif	# PYTHON22_BUILDLINK2_MK
