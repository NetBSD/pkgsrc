# $NetBSD: Makefile,v 1.1 2013/04/22 09:39:21 imil Exp $
#

VERSION=		e518a90eade4ca538468b6640dccb651e6034b9e
DISTNAME=		${VERSION}
PKGNAME=		monitoring-0.9.5
CATEGORIES=		sysutils
MASTER_SITES=		https://github.com/sebastien/monitoring/archive/
FETCH_USING=		curl

MAINTAINER=		imil@NetBSD.org
HOMEPAGE=		https://github.com/sebastien/monitoring
COMMENT=		API with DSL feel to write monitoring daemons in Python
LICENSE=		modified-bsd

WRKSRC=			${WRKDIR}/monitoring-${VERSION}

REPLACE_PYTHON+=	Sources/monitoring.py Scripts/monitoring

DOCDIR=			${PREFIX}/share/doc/monitoring
EXPDIR=			${PREFIX}/share/examples/monitoring

INSTALLATION_DIRS+=	${DOCDIR}
INSTALLATION_DIRS+=	${EXPDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/Examples/*.py ${DESTDIR}${EXPDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${DESTDIR}${DOCDIR}

.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
