# $NetBSD: Makefile,v 1.19 2001/03/07 14:33:40 drochner Exp $

DISTNAME=	Numeric-17.3.0
PKGNAME=	py-Numeric-17.3.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=numpy/}

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://numpy.sourceforge.net/
COMMENT=	Adds multidimensional numeric arrays to Python

DEPENDS+=	python>=1.6:../../lang/python

.if ${MACHINE_ARCH} == "powerpc" || ${MACHINE_ARCH} == "mips" || ${MACHINE_ARCH} == "vax"
IGNORE="${PKGNAME} needs dynamic loading"
.endif

PLIST_SRC=	${WRKDIR}/.PLIST_SRC
EVAL_PREFIX+=	PYPREFIX=python

#Together with patch/*, this works around build glitches which are
# already fixed in the numpy CVS. So all this can go on the next update.
post-extract:
	${MKDIR} ${WRKSRC}/Include/Numeric
	${MV} ${WRKSRC}/Include/*.h ${WRKSRC}/Include/Numeric

do-build:
	(cd ${WRKSRC} && ${PYPREFIX}/bin/python setup_all.py build)

post-build:
	(eval `${PYPREFIX}/bin/python ${FILESDIR}/printpypath.py` && \
	${SED} "s|PYINC|$${PYINC}|g;s|PYSITELIB|$${PYSITELIB}|g" \
	<${PKGDIR}/PLIST >${PLIST_SRC})

do-install:
	(cd ${WRKSRC} && ${PYPREFIX}/bin/python setup_all.py install)

.include "../../mk/bsd.pkg.mk"
