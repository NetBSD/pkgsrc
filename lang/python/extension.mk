# $NetBSD: extension.mk,v 1.5 2003/09/14 16:43:45 recht Exp $

# derive a python version from the package name if possible
.if defined(PKGNAME_REQD)
PYTHON_VERSION_REQD?= ${PKGNAME_REQD:C/^py([^-]*)-.*/\1/}
.endif

.include "../../lang/python/pyversion.mk"

.if defined(PYBINMODULE)
.if ${MACHINE_ARCH} == "mips" || ${MACHINE_ARCH} == "vax"
PKG_FAIL_REASON= "${PKGNAME} needs dynamic loading"
.endif
.endif

.if defined(PYDISTUTILSPKG)
PYSETUP?=		setup.py
PYSETUPBUILDARGS?=	#empty
PYSETUPINSTALLARGS?=	#empty
PYSETUPOPTARGS?=	-c -O1
_PYSETUPINSTALLARGS=	${PYSETUPINSTALLARGS} ${PYSETUPOPTARGS}
PY_PATCHPLIST?=		yes
PYSETUPSUBDIR?=		#empty

do-build:
	(cd ${WRKSRC}/${PYSETUPSUBDIR} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} \
	 ${PYSETUP} build ${PYSETUPBUILDARGS})

do-install:
	(cd ${WRKSRC}/${PYSETUPSUBDIR} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} \
	 ${PYSETUP} install ${_PYSETUPINSTALLARGS})
.endif

.if defined(PY_PATCHPLIST)
PLIST_SUBST+=	PYINC=${PYINC} PYSITELIB=${PYSITELIB}
.endif
