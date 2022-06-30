# $NetBSD: Makefile,v 1.15 2022/06/30 11:18:42 nia Exp $
#

DISTNAME=	nicovideo-dl-0.0.20190126
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_OSDN:=nicovideo-dl/70568/}

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://osdn.jp/projects/nicovideo-dl/
COMMENT=	Download videos from www.nicovideo.jp
LICENSE=	mit

USE_LANGUAGES=	# none
NO_BUILD=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

INSTALLATION_DIRS=	bin

REPLACE_PYTHON+=	nicovideo-dl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nicovideo-dl ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
