# $NetBSD: buildlink2.mk,v 1.4 2002/10/09 14:34:21 wiz Exp $

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
BUILDLINK_FILES.python20+=	include/python2.0/Python.h
BUILDLINK_FILES.python20+=	include/python2.0/abstract.h
BUILDLINK_FILES.python20+=	include/python2.0/bitset.h
BUILDLINK_FILES.python20+=	include/python2.0/bufferobject.h
BUILDLINK_FILES.python20+=	include/python2.0/cStringIO.h
BUILDLINK_FILES.python20+=	include/python2.0/ceval.h
BUILDLINK_FILES.python20+=	include/python2.0/classobject.h
BUILDLINK_FILES.python20+=	include/python2.0/cobject.h
BUILDLINK_FILES.python20+=	include/python2.0/codecs.h
BUILDLINK_FILES.python20+=	include/python2.0/compile.h
BUILDLINK_FILES.python20+=	include/python2.0/complexobject.h
BUILDLINK_FILES.python20+=	include/python2.0/dictobject.h
BUILDLINK_FILES.python20+=	include/python2.0/errcode.h
BUILDLINK_FILES.python20+=	include/python2.0/eval.h
BUILDLINK_FILES.python20+=	include/python2.0/fileobject.h
BUILDLINK_FILES.python20+=	include/python2.0/floatobject.h
BUILDLINK_FILES.python20+=	include/python2.0/frameobject.h
BUILDLINK_FILES.python20+=	include/python2.0/funcobject.h
BUILDLINK_FILES.python20+=	include/python2.0/graminit.h
BUILDLINK_FILES.python20+=	include/python2.0/grammar.h
BUILDLINK_FILES.python20+=	include/python2.0/import.h
BUILDLINK_FILES.python20+=	include/python2.0/intobject.h
BUILDLINK_FILES.python20+=	include/python2.0/intrcheck.h
BUILDLINK_FILES.python20+=	include/python2.0/listobject.h
BUILDLINK_FILES.python20+=	include/python2.0/longintrepr.h
BUILDLINK_FILES.python20+=	include/python2.0/longobject.h
BUILDLINK_FILES.python20+=	include/python2.0/marshal.h
BUILDLINK_FILES.python20+=	include/python2.0/metagrammar.h
BUILDLINK_FILES.python20+=	include/python2.0/methodobject.h
BUILDLINK_FILES.python20+=	include/python2.0/modsupport.h
BUILDLINK_FILES.python20+=	include/python2.0/moduleobject.h
BUILDLINK_FILES.python20+=	include/python2.0/node.h
BUILDLINK_FILES.python20+=	include/python2.0/object.h
BUILDLINK_FILES.python20+=	include/python2.0/objimpl.h
BUILDLINK_FILES.python20+=	include/python2.0/opcode.h
BUILDLINK_FILES.python20+=	include/python2.0/osdefs.h
BUILDLINK_FILES.python20+=	include/python2.0/parsetok.h
BUILDLINK_FILES.python20+=	include/python2.0/patchlevel.h
BUILDLINK_FILES.python20+=	include/python2.0/pgenheaders.h
BUILDLINK_FILES.python20+=	include/python2.0/pydebug.h
BUILDLINK_FILES.python20+=	include/python2.0/pyerrors.h
BUILDLINK_FILES.python20+=	include/python2.0/pyfpe.h
BUILDLINK_FILES.python20+=	include/python2.0/pymem.h
BUILDLINK_FILES.python20+=	include/python2.0/pyport.h
BUILDLINK_FILES.python20+=	include/python2.0/pystate.h
BUILDLINK_FILES.python20+=	include/python2.0/pythonrun.h
BUILDLINK_FILES.python20+=	include/python2.0/pythread.h
BUILDLINK_FILES.python20+=	include/python2.0/rangeobject.h
BUILDLINK_FILES.python20+=	include/python2.0/sliceobject.h
BUILDLINK_FILES.python20+=	include/python2.0/stringobject.h
BUILDLINK_FILES.python20+=	include/python2.0/structmember.h
BUILDLINK_FILES.python20+=	include/python2.0/sysmodule.h
BUILDLINK_FILES.python20+=	include/python2.0/token.h
BUILDLINK_FILES.python20+=	include/python2.0/traceback.h
BUILDLINK_FILES.python20+=	include/python2.0/tupleobject.h
BUILDLINK_FILES.python20+=	include/python2.0/ucnhash.h
BUILDLINK_FILES.python20+=	include/python2.0/unicodeobject.h
BUILDLINK_FILES.python20+=	include/python2.0/config.h
BUILDLINK_FILES.python20+=	lib/python2.0/config/libpython2.0.*
BUILDLINK_TRANSFORM+=		l:python:python2.0

BUILDLINK_CPPFLAGS.python20+= \
	-I${BUILDLINK_PREFIX.python20}/include/python2.0
BUILDLINK_LDFLAGS.python20+= \
	-L${BUILDLINK_PREFIX.python20}/lib/python2.0/config		\
	-Wl,-R${BUILDLINK_PREFIX.python20}/lib/python2.0/config

BUILDLINK_TARGETS+=	python20-buildlink

python20-buildlink: _BUILDLINK_USE

.endif	# PYTHON20_BUILDLINK2_MK
