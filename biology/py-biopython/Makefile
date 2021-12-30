# $NetBSD: Makefile,v 1.6 2021/12/30 13:05:27 adam Exp $

DISTNAME=	biopython-1.74
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://biopython.org/DIST/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://biopython.org/
COMMENT=	Python libraries for computational molecular biology
LICENSE=	biopython

USE_TOOLS+=	pax

INSTALLATION_DIRS+=	share/doc/biopython share/examples/biopython

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.rst ${DESTDIR}${PREFIX}/share/doc/biopython
	${INSTALL_DATA} ${WRKSRC}/Doc/Tutorial.pdf ${DESTDIR}${PREFIX}/share/doc/biopython
	cd ${WRKSRC}/Doc/examples && ${PAX} -rw . ${DESTDIR}${PREFIX}/share/examples/biopython

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
