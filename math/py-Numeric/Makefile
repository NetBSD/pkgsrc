# $NetBSD: Makefile,v 1.20 2001/04/09 11:50:51 drochner Exp $

DISTNAME=	Numeric-19.0.0
PKGNAME=	py-Numeric-19.0.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=numpy/}

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://numpy.sourceforge.net/
COMMENT=	Adds multidimensional numeric arrays to Python

DEPENDS+=	python>=2.0:../../lang/python

.if ${MACHINE_ARCH} == "powerpc" || ${MACHINE_ARCH} == "mips" || ${MACHINE_ARCH} == "vax"
IGNORE="${PKGNAME} needs dynamic loading"
.endif

PLIST_SRC=	${WRKDIR}/.PLIST_SRC
EVAL_PREFIX+=	PYPREFIX=python

do-build:
	(cd ${WRKSRC} && ${PYPREFIX}/bin/python setup_all.py build)

post-build:
	(eval `${PYPREFIX}/bin/python ${FILESDIR}/printpypath.py` && \
	${SED} "s|PYINC|$${PYINC}|g;s|PYSITELIB|$${PYSITELIB}|g" \
	<${PKGDIR}/PLIST >${PLIST_SRC})

do-install:
	(cd ${WRKSRC} && ${PYPREFIX}/bin/python setup_all.py install)

.include "../../mk/bsd.pkg.mk"
