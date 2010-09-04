# $NetBSD: srcdist.mk,v 1.33 2010/09/04 15:31:29 tron Exp $

.include "../../lang/python/pyversion.mk"

.if ${_PYTHON_VERSION} == "26"

DISTNAME=	Python-2.6.6
EXTRACT_SUFX=	.tar.bz2
DISTINFO_FILE=	${.CURDIR}/../../lang/python26/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python26/patches
PYSUBDIR=	Python-2.6.6
WRKSRC=		${WRKDIR}/${PYSUBDIR}
MASTER_SITES=	ftp://ftp.python.org/pub/python/2.6/

.elif ${_PYTHON_VERSION} == "25"

DISTNAME=	Python-2.5.5
EXTRACT_SUFX=	.tar.bz2
DISTINFO_FILE=	${.CURDIR}/../../lang/python25/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python25/patches
PYSUBDIR=	Python-2.5.5
WRKSRC=		${WRKDIR}/${PYSUBDIR}
MASTER_SITES=	ftp://ftp.python.org/pub/python/2.5/

.elif ${_PYTHON_VERSION} == "24"

DISTNAME=	Python-2.4.5
EXTRACT_SUFX=	.tar.bz2
DISTINFO_FILE=	${.CURDIR}/../../lang/python24/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python24/patches
PYSUBDIR=	Python-2.4.5
WRKSRC=		${WRKDIR}/${PYSUBDIR}
MASTER_SITES=	ftp://ftp.python.org/pub/python/2.4/

.endif

.if defined(PYDISTUTILSPKG)
# This is used for standard modules shipped with Python but build as
# separate packages.

python-std-patchsetup:
	${SED} ${PY_SETUP_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/} \
		<${FILESDIR}/setup.py >${WRKSRC}/setup.py

post-extract: python-std-patchsetup
.endif
