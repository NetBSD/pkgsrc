# $NetBSD: srcdist.mk,v 1.40 2020/01/08 13:44:41 joerg Exp $

.include "../../lang/python/pyversion.mk"

.sinclude "${.CURDIR}/${PYPKGSRCDIR}/dist.mk"

PYSUBDIR=	${DISTNAME}
WRKSRC=		${WRKDIR}/${PYSUBDIR}

.if defined(PYDISTUTILSPKG)
# This is used for standard modules shipped with Python but build as
# separate packages.

# Standard modules depend on their own version
BUILDLINK_API_DEPENDS.${PYPACKAGE}+=	${PYPACKAGE}>=${PY_DISTVERSION}
BUILDLINK_ABI_DEPENDS.${PYPACKAGE}+=	${PYPACKAGE}>=${PY_DISTVERSION}

python-std-patchsetup:
	${SED} ${PY_SETUP_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/} \
		<${FILESDIR}/setup.py >${WRKSRC}/setup.py

post-patch: python-std-patchsetup
.endif
