# $NetBSD: Makefile,v 1.10 2016/07/29 07:52:36 nils Exp $

VERSION=		0.7.13
DISTNAME=		cuisine-${VERSION}
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_PYPI:=c/cuisine/}

MAINTAINER=		imil@NetBSD.org
HOMEPAGE=		https://github.com/sebastien/cuisine
COMMENT=		Small set of functions that sit on top of Fabric
LICENSE=		modified-bsd

DEPENDS+=		fabric>=1.7.0:../../sysutils/fabric

PYTHON_VERSIONS_INCOMPATIBLE=	34 35 # not yet ported as of 0.6.4

WRKSRC=			${WRKDIR}/cuisine-${VERSION}

DOCDIR=			${PREFIX}/share/doc/cuisine

INSTALLATION_DIRS+=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.rst ${DESTDIR}${DOCDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
