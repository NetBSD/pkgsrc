# $NetBSD: extension.mk,v 1.18 2008/04/24 01:39:25 tnn Exp $

# derive a python version from the package name if possible
# optionally handled quoted package names
.if defined(PKGNAME_REQD)
PYTHON_VERSION_REQD?= ${PKGNAME_REQD:C/(^.*-|^)py([0-9][0-9])-.*/\2/}
.endif

.include "../../lang/python/pyversion.mk"

.if defined(PYBINMODULE)
.if ${MACHINE_ARCH} == "mips" || ${MACHINE_ARCH} == "vax"
PKG_FAIL_REASON+=	"${PKGNAME} needs dynamic loading"
.endif
.endif

.if defined(PYDISTUTILSPKG)
.include "../../mk/bsd.prefs.mk"

PYSETUP?=		setup.py
PYSETUPBUILDARGS?=	#empty
PYSETUPINSTALLARGS?=	#empty
PYSETUPOPTARGS?=	-c -O1
_PYSETUPINSTALLARGS=	${PYSETUPINSTALLARGS} ${PYSETUPOPTARGS} ${_PYSETUPTOOLSINSTALLARGS}
.if ${_USE_DESTDIR} != "no"
_PYSETUPINSTALLARGS+=	--root=${DESTDIR:Q}
.endif
PY_PATCHPLIST?=		yes
PYSETUPSUBDIR?=		#empty

PY_NO_EGG?=		yes
.if !empty(PY_NO_EGG:M[yY][eE][sS])
# see python25/patches/patch-av
INSTALL_ENV+=		PKGSRC_PYTHON_NO_EGG=defined
.endif

do-build:
	(cd ${WRKSRC}/${PYSETUPSUBDIR} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} \
	 ${PYSETUP} build ${PYSETUPBUILDARGS})

do-install:
	(cd ${WRKSRC}/${PYSETUPSUBDIR} && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	 ${PYTHONBIN} ${PYSETUP} "install" ${_PYSETUPINSTALLARGS})
.endif

.if defined(PY_PATCHPLIST)
PLIST_SUBST+=	PYINC=${PYINC} PYSITELIB=${PYSITELIB}
.endif
