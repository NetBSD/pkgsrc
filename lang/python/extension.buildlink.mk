# $NetBSD: extension.buildlink.mk,v 1.12 2002/09/20 22:53:21 jlam Exp $

# derive a python version from the package name if possible
.if defined(PKGNAME_REQD)
PYTHON_VERSION_REQD?= ${PKGNAME_REQD:C/^py([^-]*)-.*/\1/}
.endif

.include "../../lang/python/pyversion.mk"

.if defined(PYBINMODULE)
.if ${MACHINE_ARCH} == "mips" || ${MACHINE_ARCH} == "vax"
IGNORE="${PKGNAME} needs dynamic loading"
.endif
.endif

.if defined(PYDISTUTILSPKG)
PYSETUP?=		setup.py
PYSETUPBUILDARGS?=	#empty
PYSETUPINSTALLARGS?=	#empty
PY_PATCHPLIST?=		yes

do-build:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} \
	 ${PYSETUP} ${PYSETUPBUILDARGS} build)

do-install:
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} \
	 ${PYSETUP} ${PYSETUPINSTALLARGS} install)
.endif

.if defined(PY_PATCHPLIST)
PLIST_SUBST+=	PYINC=${PYINC} PYSITELIB=${PYSITELIB}
.endif
