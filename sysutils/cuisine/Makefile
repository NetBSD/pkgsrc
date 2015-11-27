# $NetBSD: Makefile,v 1.6 2015/11/27 14:21:26 nils Exp $

VERSION=		0.7.11
DISTNAME=		cuisine-${VERSION}
#PKGNAME=		cuisine-0.7.11
CATEGORIES=		sysutils
MASTER_SITES=		https://pypi.python.org/packages/source/c/cuisine/

MAINTAINER=		imil@NetBSD.org
HOMEPAGE=		https://github.com/sebastien/cuisine
COMMENT=		Small set of functions that sit on top of Fabric
LICENSE=		modified-bsd

DEPENDS+=		fabric>=1.7.0:../../sysutils/fabric

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 # not yet ported as of 0.6.4

WRKSRC=			${WRKDIR}/cuisine-${VERSION}

DOCDIR=			${PREFIX}/share/doc/cuisine

INSTALLATION_DIRS+=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.rst ${DESTDIR}${DOCDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
