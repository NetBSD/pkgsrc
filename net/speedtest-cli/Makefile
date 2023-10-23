# $NetBSD: Makefile,v 1.15 2023/10/23 06:37:51 wiz Exp $

DISTNAME=	speedtest-cli-2.1.3
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=sivel/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sivel/speedtest-cli
COMMENT=	Command line client for use with speedtest.net
LICENSE=	apache-2.0

REPLACE_PYTHON=	*.py

PYTHON_VERSIONED_DEPENDENCIES+=	setuptools

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

USE_PKG_RESOURCES=	yes

post-install:
	${INSTALL_MAN} ${WRKSRC}/speedtest-cli.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/speedtest-cli.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/speedtest.1

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
