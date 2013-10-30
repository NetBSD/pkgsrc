# $NetBSD: extension.mk,v 1.34 2013/10/30 08:39:07 obache Exp $

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
PYSETUPBUILDARGS?=	#empty
PYSETUPARGS?=		#empty
PYSETUPINSTALLARGS?=	#empty
PYSETUPOPTARGS?=	-c -O1
_PYSETUPINSTALLARGS=	${PYSETUPINSTALLARGS} ${PYSETUPOPTARGS} ${_PYSETUPTOOLSINSTALLARGS}
.if ${_USE_DESTDIR} != "no"
_PYSETUPINSTALLARGS+=	--root=${DESTDIR:Q}
.endif
PY_PATCHPLIST?=		yes
PYSETUPINSTALLARGS?=	#empty
PYSETUPTESTTARGET?=	test
PYSETUPTESTARGS?=	#empty
PYSETUPSUBDIR?=		#empty

do-build:
	(cd ${WRKSRC}/${PYSETUPSUBDIR} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} \
	 ${PYSETUP} ${PYSETUPARGS} ${PYSETUPBUILDTARGET} ${PYSETUPBUILDARGS})

do-install:
	(cd ${WRKSRC}/${PYSETUPSUBDIR} && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	 ${PYTHONBIN} ${PYSETUP} ${PYSETUPARGS} "install" ${_PYSETUPINSTALLARGS})
.if !target(do-test) && !(defined(TEST_TARGET) && !empty(TEST_TARGET))
do-test:
	(cd ${WRKSRC}/${PYSETUPSUBDIR} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} \
	 ${PYSETUP} ${PYSETUPARGS} ${PYSETUPTESTTARGET} ${PYSETUPTESTARGS})
.endif

.endif

# PY_NO_EGG suppress the installation of the egg info file (and
# therefore its inclusion in the package).  Python practice is be to
# use these files to let 'require' verify that python distributions
# are present, and therefore the default value of PY_NO_EGG=yes causes
# pkgsrc not to conform to python norms.  The reason for this behavior
# appears to be that creating egg info files was new in Python 2.5.
PY_NO_EGG?=		yes
.if !empty(PY_NO_EGG:M[yY][eE][sS])
# see python26/patches/patch-av
INSTALL_ENV+=		PKGSRC_PYTHON_NO_EGG=defined
.endif

.if defined(PY_PATCHPLIST)
PLIST_SUBST+=	PYINC=${PYINC} PYLIB=${PYLIB} PYSITELIB=${PYSITELIB}
.endif

# prepare Python>=32 bytecode file location change
.if empty(_PYTHON_VERSION:M2?) && ${_PYTHON_VERSION} != "31"
PLIST_AWK+=	-f ${PKGSRCDIR}/lang/python/plist-python.awk
PLIST_AWK_ENV+=	PYTHON_SOABI="cpython-${_PYTHON_VERSION}"
.endif
