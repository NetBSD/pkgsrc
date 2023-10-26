# $NetBSD: extension.mk,v 1.64 2023/10/26 10:18:34 wiz Exp $

.include "../../lang/python/pyversion.mk"

# This mk fragment is included to handle packages that create
# extensions to python, which by definition are those that place files
# in ${PYSITELIB}.  Extensions can be implemented via setuptools as
# eggs (see egg.mk), via wheels (see wheel.mk), or via more ad hoc
# methods.

.if !empty(PYDISTUTILSPKG:M[yY][eE][sS])
.include "../../mk/bsd.prefs.mk"

PYSETUP?=		setup.py
PYSETUPBUILDTARGET?=	build
PYSETUPBUILDARGS?=	# empty
# Python 3.5+ supports parallel building
.  if defined(MAKE_JOBS) && ${_PYTHON_VERSION} != 27
.    if !defined(MAKE_JOBS_SAFE) || empty(MAKE_JOBS_SAFE:M[nN][oO])
PYSETUPBUILDARGS+=	-j${MAKE_JOBS}
.    endif
.  endif
.  if ${USE_CROSS_COMPILE:U:tl} == "yes"
PYSETUPBUILDARGS+=	--executable=${PYTHONBIN:Q}
.  endif
PYSETUPARGS?=		# empty
PYSETUPINSTALLARGS?=	# empty
PYSETUPOPTARGS?=	-c -O1
_PYSETUPINSTALLARGS=	${PYSETUPINSTALLARGS} ${PYSETUPOPTARGS} ${_PYSETUPTOOLSINSTALLARGS}
_PYSETUPINSTALLARGS+=	--root=${DESTDIR:Q}
PY_PATCHPLIST?=		yes
PYSETUPTESTTARGET?=	test
PYSETUPTESTARGS?=	# empty
PYSETUPSUBDIR?=		# empty

do-build:
	(cd ${WRKSRC}/${PYSETUPSUBDIR} && ${SETENV} ${MAKE_ENV} \
	 ${TOOL_PYTHONBIN} ${PYSETUP} ${PYSETUPARGS} ${PYSETUPBUILDTARGET} \
	 ${PYSETUPBUILDARGS})

do-install:
	(cd ${WRKSRC}/${PYSETUPSUBDIR} && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	 ${TOOL_PYTHONBIN} ${PYSETUP} ${PYSETUPARGS} "install" \
	 ${_PYSETUPINSTALLARGS})

.  if !target(do-test) && !(defined(TEST_TARGET) && !empty(TEST_TARGET))
do-test:
	(cd ${WRKSRC}/${PYSETUPSUBDIR} && ${SETENV} ${TEST_ENV} \
	 ${TOOL_PYTHONBIN} ${PYSETUP} ${PYSETUPARGS} ${PYSETUPTESTTARGET} \
	 ${PYSETUPTESTARGS})
.  endif

.endif

.if defined(PY_PATCHPLIST)
PLIST_SUBST+=	PYINC=${PYINC} PYLIB=${PYLIB} PYSITELIB=${PYSITELIB}
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
.endif

# mostly for ALTERNATIVES files
FILES_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

# Python>=3.2 bytecode file location change
# http://www.python.org/dev/peps/pep-3147/
.if empty(_PYTHON_VERSION:M2?)
PLIST_AWK+=		-f ${PKGSRCDIR}/lang/python/plist-python.awk
PLIST_AWK_ENV+=		PYVERS="${PYVERSSUFFIX:S/.//}"
EARLY_PRINT_PLIST_AWK+=	/^[^@]/ && /[^\/]+\.py[co]$$/ {
EARLY_PRINT_PLIST_AWK+=	gsub(/__pycache__\//, "")
EARLY_PRINT_PLIST_AWK+=	gsub(/opt-1\.pyc$$/, "pyo")
EARLY_PRINT_PLIST_AWK+=	gsub(/\.cpython-${_PYTHON_VERSION}/, "")}
PRINT_PLIST_AWK+=	/bin\// { sub(/${PYVERSSUFFIX}/, "$${PYVERSSUFFIX}") }
PRINT_PLIST_AWK+=	/man\// { sub(/${PYVERSSUFFIX}/, "$${PYVERSSUFFIX}") }
PRINT_PLIST_AWK+=	/share\/doc\// { sub(/${PYVERSSUFFIX}/, "$${PYVERSSUFFIX}") }
.endif

# For running tests before installation of the package,
# this is sometimes needed; or setting
# TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

DISTUTILS_BUILDDIR_IN_TEST_ENV?=	no

.if ${DISTUTILS_BUILDDIR_IN_TEST_ENV} == "yes"
DISTUTILS_BUILDDIR_CMD=	cd ${WRKSRC} && ${TOOL_PYTHONBIN} ${.CURDIR}/../../lang/python/distutils-builddir.py
TEST_ENV+=	PYTHONPATH=${DISTUTILS_BUILDDIR_CMD:sh}
.endif
