# $NetBSD: extension.mk,v 1.57 2020/06/10 16:11:07 leot Exp $

.include "../../lang/python/pyversion.mk"

# Packages that are a non-egg distutils extension should set
# PYDISTUTILSPKG=YES and include this mk file.

# This mk fragment is included to handle packages that create
# extensions to python, which by definition are those that place files
# in ${PYSITELIB}.  Extensions can be implemented via setuptools as
# eggs (see egg.mk), via distutils (confusing, with an egg-info file,
# even though they are not eggs), or via more ad hocs methods.

.if defined(PYDISTUTILSPKG)
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
	(cd ${WRKSRC}/${PYSETUPSUBDIR} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} \
	 ${PYSETUP} ${PYSETUPARGS} ${PYSETUPBUILDTARGET} ${PYSETUPBUILDARGS})

do-install:
	(cd ${WRKSRC}/${PYSETUPSUBDIR} && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	 ${PYTHONBIN} ${PYSETUP} ${PYSETUPARGS} "install" ${_PYSETUPINSTALLARGS})

.  if !target(do-test) && !(defined(TEST_TARGET) && !empty(TEST_TARGET))
do-test:
	(cd ${WRKSRC}/${PYSETUPSUBDIR} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} \
	 ${PYSETUP} ${PYSETUPARGS} ${PYSETUPTESTTARGET} ${PYSETUPTESTARGS})
.  endif

.endif

# PY_NO_EGG suppress the installation of the egg info file (and
# therefore its inclusion in the package).  Python practice is be to
# use these files to let 'require' verify that python distributions
# are present, and therefore the default value of PY_NO_EGG=yes causes
# pkgsrc not to conform to python norms.  The reason for this behavior
# appears to be that creating egg info files was new in Python 2.5.
PY_NO_EGG?=		yes
.if !empty(PY_NO_EGG:M[yY][eE][sS])
# see python*/patches/patch-Lib_distutils_command_install.py
INSTALL_ENV+=		PKGSRC_PYTHON_NO_EGG=defined
.endif

.if defined(PY_PATCHPLIST)
PLIST_SUBST+=	PYINC=${PYINC} PYLIB=${PYLIB} PYSITELIB=${PYSITELIB}
PLIST_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}
.endif

# mostly for ALTERNATIVES files
FILES_SUBST+=	PYVERSSUFFIX=${PYVERSSUFFIX}

# prepare Python>=3.2 bytecode file location change
# http://www.python.org/dev/peps/pep-3147/
.if empty(_PYTHON_VERSION:M2?)
PLIST_AWK+=		-f ${PKGSRCDIR}/lang/python/plist-python.awk
PLIST_AWK_ENV+=		PYVERS="${PYVERSSUFFIX:S/.//}"
EARLY_PRINT_PLIST_AWK+=	/^[^@]/ && /[^\/]+\.py[co]$$/ {
EARLY_PRINT_PLIST_AWK+=	gsub(/__pycache__\//, "")
EARLY_PRINT_PLIST_AWK+=	gsub(/opt-1\.pyc$$/, "pyo")
EARLY_PRINT_PLIST_AWK+=	gsub(/\.cpython-${_PYTHON_VERSION}/, "")}
.endif

DISTUTILS_BUILDDIR_IN_TEST_ENV?=	no

.if ${DISTUTILS_BUILDDIR_IN_TEST_ENV} == "yes"
DISTUTILS_BUILDDIR_CMD=	cd ${WRKSRC} && ${PYTHONBIN} ${.CURDIR}/../../lang/python/distutils-builddir.py
TEST_ENV+=	PYTHONPATH=${DISTUTILS_BUILDDIR_CMD:sh}
.endif
