# $NetBSD: srcdist.mk,v 1.47 2026/05/28 03:58:33 adam Exp $

.include "../../lang/python/pyversion.mk"

.sinclude "${.CURDIR}/${PYPKGSRCDIR}/dist.mk"

PYSUBDIR=	${DISTNAME}
WRKSRC=		${WRKDIR}/${PYSUBDIR}

.if !empty(PYDISTUTILSPKG:M[yY][eE][sS])
# This is used for standard modules shipped with Python but built as
# separate packages.

# Standard modules depend on their own version
BUILDLINK_API_DEPENDS.${PYPACKAGE}+=	${PYPACKAGE}>=${PY_DISTVERSION}
BUILDLINK_ABI_DEPENDS.${PYPACKAGE}+=	${PYPACKAGE}>=${PY_DISTVERSION}

.include "../../mk/bsd.prefs.mk"

.  if ${USE_CROSS_COMPILE:tl} == "yes"
TOOL_DEPENDS+=	${PYDEPENDENCY}
DEPENDS+=	${PYDEPENDENCY}
ALL_ENV+=	_PYTHON_PROJECT_BASE=${WRKSRC}
CPPFLAGS+=	-I${LOCALBASE}/${PYINC:Q}
.  endif

python-std-patchsetup:
	${SED} ${PY_SETUP_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/} \
		<${FILESDIR}/setup.py >${WRKSRC}/setup.py

post-patch: python-std-patchsetup

python-std-setuptools-cleanup:
	${RM} -rf ${DESTDIR}${PREFIX}/${PYLIB}/lib-dynload/UNKNOWN*

post-install: python-std-setuptools-cleanup

.endif
