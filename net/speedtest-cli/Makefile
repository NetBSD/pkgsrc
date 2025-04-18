# $NetBSD: Makefile,v 1.18 2025/04/18 04:39:49 wiz Exp $

DISTNAME=	speedtest-cli-2.1.3
PKGREVISION=	6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=sivel/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sivel/speedtest-cli
COMMENT=	Command line client for use with speedtest.net
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools

REPLACE_PYTHON=	*.py

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

post-install:
	${INSTALL_MAN} ${WRKSRC}/speedtest-cli.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/speedtest-cli.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/speedtest.1

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
