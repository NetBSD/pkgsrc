# $NetBSD: application.mk,v 1.11 2014/01/25 10:45:50 wiz Exp $
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
REPLACE.python.old=	.*python[^ ]*
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python=	${REPLACE_PYTHON}
.endif
