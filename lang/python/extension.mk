# $NetBSD: extension.mk,v 1.26 2010/07/21 11:29:10 wiz Exp $

.include "../../lang/python/pyversion.mk"

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
PYSETUPSUBDIR?=		#empty

do-build:
	(cd ${WRKSRC}/${PYSETUPSUBDIR} && ${SETENV} ${MAKE_ENV} ${PYTHONBIN} \
	 ${PYSETUP} ${PYSETUPARGS} ${PYSETUPBUILDTARGET} ${PYSETUPBUILDARGS})

do-install:
	(cd ${WRKSRC}/${PYSETUPSUBDIR} && ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
	 ${PYTHONBIN} ${PYSETUP} ${PYSETUPARGS} "install" ${_PYSETUPINSTALLARGS})
.endif

PY_NO_EGG?=		yes
.if !empty(PY_NO_EGG:M[yY][eE][sS])
# see python25/patches/patch-av
INSTALL_ENV+=		PKGSRC_PYTHON_NO_EGG=defined
.endif

.if defined(PY_PATCHPLIST)
PLIST_SUBST+=	PYINC=${PYINC} PYSITELIB=${PYSITELIB}
.endif
