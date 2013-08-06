# $NetBSD: Makefile,v 1.2 2013/08/06 18:47:23 gls Exp $
#

VERSION=		b79718f8f69d17a075b7a626e32c1ed1200445f8
DISTNAME=		${VERSION}
PKGNAME=		cuisine-0.6.4
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
