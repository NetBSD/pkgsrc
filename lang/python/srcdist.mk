# $NetBSD: srcdist.mk,v 1.42 2022/09/06 09:05:59 nia Exp $

.include "../../lang/python/pyversion.mk"

.sinclude "${.CURDIR}/${PYPKGSRCDIR}/dist.mk"

PYSUBDIR=	${DISTNAME}
WRKSRC=		${WRKDIR}/${PYSUBDIR}

.if !empty(PYDISTUTILSPKG:M[yY][eE][sS])
# This is used for standard modules shipped with Python but build as
# separate packages.

# Standard modules depend on their own version
BUILDLINK_API_DEPENDS.${PYPACKAGE}+=	${PYPACKAGE}>=${PY_DISTVERSION}
BUILDLINK_ABI_DEPENDS.${PYPACKAGE}+=	${PYPACKAGE}>=${PY_DISTVERSION}

python-std-patchsetup:
	${SED} ${PY_SETUP_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/} \
		<${FILESDIR}/setup.py >${WRKSRC}/setup.py

post-patch: python-std-patchsetup

python-std-setuptools-cleanup:
	${RM} -rf ${DESTDIR}/${PREFIX}/${PYLIB}/lib-dynload/UNKNOWN*

post-install: python-std-setuptools-cleanup

.endif
