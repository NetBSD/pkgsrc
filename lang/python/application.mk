# $NetBSD: application.mk,v 1.12 2017/07/03 18:13:43 joerg Exp $
#
# Replace the #! interpreter for Python scripts.
#
# This mk fragment should be included in all python packages that
# install python scripts, or at least those that don't use setuptools
# or some other mechanism to set the real path.  Specifically, it is
# reasonable to include both egg.mk and application.mk.
#
# Package-settable variables:
#
# REPLACE_PYTHON
#	A list of Python scripts to be installed, relative to ${WRKSRC}.
#
# Keywords: python
#

.include "../../lang/python/pyversion.mk"

.if defined(REPLACE_PYTHON)
REPLACE_INTERPRETER+=	python
REPLACE.python.old=	.*python3\{0,1\}[^ ]*
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python=	${REPLACE_PYTHON}
.endif
