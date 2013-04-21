# $NetBSD: Makefile,v 1.1 2013/04/21 21:31:34 imil Exp $
#

VERSION=		fce9cea592f7132898a419e07e704d45b4e81d4f
DISTNAME=		${VERSION}
PKGNAME=		cuisine-0.5.8
CATEGORIES=		sysutils
MASTER_SITES=		https://github.com/sebastien/cuisine/archive/
FETCH_USING=		curl

MAINTAINER=		imil@NetBSD.org
HOMEPAGE=		https://github.com/sebastien/cuisine
COMMENT=		Small set of functions that sit on top of Fabric
LICENSE=		modified-bsd

DEPENDS+=		fabric>=1.6.0:../../sysutils/fabric

WRKSRC=			${WRKDIR}/cuisine-${VERSION}

DOCDIR=			${PREFIX}/share/doc/cuisine

INSTALLATION_DIRS+=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/api/cuisine-api.html ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${DESTDIR}${DOCDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
