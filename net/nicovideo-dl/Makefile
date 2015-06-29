# $NetBSD: Makefile,v 1.8 2015/06/29 11:06:48 ryoon Exp $
#

DISTNAME=	nicovideo-dl-0.0.20120212
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_OSDN:=nicovideo-dl/56304/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://osdn.jp/projects/nicovideo-dl/
COMMENT=	Download videos from www.nicovideo.jp
LICENSE=	mit

USE_LANGUAGES=	# none
NO_BUILD=	yes

INSTALLATION_DIRS=	bin

REPLACE_PYTHON+=	nicovideo-dl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/nicovideo-dl ${DESTDIR}${PREFIX}/bin

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
