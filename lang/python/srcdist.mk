# $NetBSD: srcdist.mk,v 1.37 2018/07/03 03:55:40 adam Exp $

.include "../../lang/python/pyversion.mk"

.sinclude "${.CURDIR}/${PYPKGSRCDIR}/dist.mk"

PYSUBDIR=	${DISTNAME}
WRKSRC=		${WRKDIR}/${PYSUBDIR}

.if defined(PYDISTUTILSPKG)
# This is used for standard modules shipped with Python but build as
# separate packages.

.  if ${PYVERSSUFFIX} == "3.5" || ${PYVERSSUFFIX} == "3.6" || ${PYVERSSUFFIX} == "3.7"
EXTRACT_ELEMENTS+=	${PYSUBDIR}/Modules/clinic
.  endif

python-std-patchsetup:
	${SED} ${PY_SETUP_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/} \
		<${FILESDIR}/setup.py >${WRKSRC}/setup.py

post-extract: python-std-patchsetup
.endif
