# $NetBSD: application.mk,v 1.1 2002/09/21 23:47:03 jlam Exp $

.include "../../lang/python/pyversion.mk"

# replace shell magic by python version specific path
# PYTHON_PATCH_SCRIPTS is a list of Python scripts to be installed,
#  relative to ${WRKSRC}

_PYTHON_PATCH_SCRIPT_SED=	-e "1s;^\#!.*python;\#!${PYTHONBIN};"

.if defined(PYTHON_PATCH_SCRIPTS)
python-patch-scripts:
.for s in ${PYTHON_PATCH_SCRIPTS}
	${CP} ${WRKSRC}/$s ${WRKSRC}/$s.tmp
	${CHMOD} +w ${WRKSRC}/$s
	${SED} ${_PYTHON_PATCH_SCRIPT_SED} <${WRKSRC}/$s.tmp >${WRKSRC}/$s
.endfor

post-patch: python-patch-scripts
.endif
