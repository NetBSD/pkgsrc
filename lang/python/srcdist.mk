# $NetBSD: srcdist.mk,v 1.25 2009/02/09 21:09:21 joerg Exp $

.include "../../lang/python/pyversion.mk"

.if ${_PYTHON_VERSION} == "25"

DISTNAME=	Python-2.5.2
EXTRACT_SUFX=	.tar.bz2
DISTINFO_FILE=	${.CURDIR}/../../lang/python25/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python25/patches
PYSUBDIR=	Python-2.5.2
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

.elif ${_PYTHON_VERSION} == "23"

DISTNAME=	Python-2.3.7
EXTRACT_SUFX=	.tgz
DISTINFO_FILE=	${.CURDIR}/../../lang/python23/distinfo
PATCHDIR=	${.CURDIR}/../../lang/python23/patches
PYSUBDIR=	Python-2.3.7
WRKSRC=		${WRKDIR}/${PYSUBDIR}
MASTER_SITES=	ftp://ftp.python.org/pub/python/2.3.7/

.endif

.if defined(PYDISTUTILSPKG)
# This is used for standard modules shipped with Python but build as
# separate packages.

python-std-patchsetup:
	${SED} ${PY_SETUP_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/} \
		<${FILESDIR}/setup.py >${WRKSRC}/setup.py

post-extract: python-std-patchsetup
.endif
