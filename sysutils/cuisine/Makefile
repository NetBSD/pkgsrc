# $NetBSD: Makefile,v 1.15 2019/04/26 14:12:45 maya Exp $

VERSION=		0.7.13
DISTNAME=		cuisine-${VERSION}
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_PYPI:=c/cuisine/}

MAINTAINER=		imil@NetBSD.org
HOMEPAGE=		https://github.com/sebastien/cuisine
COMMENT=		Small set of functions that sit on top of Fabric
LICENSE=		modified-bsd

DEPENDS+=		fabric>=1.7.0:../../sysutils/fabric

PYTHON_VERSIONS_INCOMPATIBLE=	36 37 # not yet ported as of 0.6.4

WRKSRC=			${WRKDIR}/cuisine-${VERSION}

DOCDIR=			${PREFIX}/share/doc/cuisine

INSTALLATION_DIRS+=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README.rst ${DESTDIR}${DOCDIR}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
