# $NetBSD: application.mk,v 1.14 2023/06/27 10:31:21 riastradh Exp $
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
#	A list of filename patterns for Python scripts to be installed,
#	relative to ${WRKSRC}.
#
# Keywords: python
#

.include "../../lang/python/pyversion.mk"

# XXX Handle TOOL_PYTHONBIN replacement too.
.if defined(REPLACE_PYTHON)
REPLACE_INTERPRETER+=	python
REPLACE.python.old=	.*python3\{0,1\}[^ ]*
REPLACE.python.new=	${PYTHONBIN}
REPLACE_FILES.python=	${REPLACE_PYTHON}
.endif
