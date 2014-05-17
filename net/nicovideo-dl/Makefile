# $NetBSD: Makefile,v 1.7 2014/05/17 16:10:47 wiz Exp $
#

DISTNAME=	nicovideo-dl-0.0.20120212
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP:=nicovideo-dl/56304/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://sourceforge.jp/projects/nicovideo-dl/
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
