# $NetBSD: Makefile,v 1.17 2001/01/15 11:58:25 drochner Exp $

DISTNAME=	Numeric-17.2.0
PKGNAME=	py-Numeric-17.2.0
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=numpy/}

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://numpy.sourceforge.net/

DEPENDS+=	python>=1.6:../../lang/python

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
