# $NetBSD: application.mk,v 1.8 2007/01/24 09:59:02 rillig Exp $

.include "../../lang/python/pyversion.mk"

# replace shell magic by python version specific path
#
# PYTHON_PATCH_SCRIPTS is a list of Python scripts to be installed,
#  relative to ${WRKSRC}
#
# Keywords: python
#

.if defined(PYTHON_PATCH_SCRIPTS)
REPLACE_INTERPRETER+=	python
REPLACE.python.old=	.*python[^ ]*
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python=	${PYTHON_PATCH_SCRIPTS}
.endif
