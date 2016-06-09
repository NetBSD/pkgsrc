# $NetBSD: Makefile,v 1.2 2016/06/09 06:23:40 wiz Exp $

DISTNAME=	speedtest-cli-0.3.2
MASTER_SITES=	${MASTER_SITE_GITHUB:=sivel/}
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	net

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sivel/speedtest-cli/
COMMENT=	Command line client for use with speedtest.net
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-expat:../../textproc/py-expat
DEPENDS+=	${PYPKGPREFIX}-setuptools:../../devel/py-setuptools

#NO_BUILD=	yes

REPLACE_PYTHON=	*.py

post-install:
	${INSTALL_MAN_DIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/speedtest-cli.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/speedtest-cli.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/speedtest.1

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
