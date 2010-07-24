# $NetBSD: application.mk,v 1.10 2010/07/24 18:12:11 gdt Exp $
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
# PYTHON_PATCH_SCRIPTS
#	The same as REPLACE_PYTHON.
#
# Keywords: python
#

.include "../../lang/python/pyversion.mk"

.if defined(PYTHON_PATCH_SCRIPTS) || defined(REPLACE_PYTHON)
REPLACE_INTERPRETER+=	python
REPLACE.python.old=	.*python[^ ]*
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python=	${PYTHON_PATCH_SCRIPTS} ${REPLACE_PYTHON}
.endif
