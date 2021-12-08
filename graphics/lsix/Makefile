# $NetBSD: Makefile,v 1.6 2021/12/08 16:05:00 adam Exp $

DISTNAME=	lsix-1.8
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=hackerb9/}

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://github.com/hackerb9/lsix/
COMMENT=	Like ls, but for images
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	bash:run
USE_LANGUAGES=	# none
NO_BUILD=	yes
REPLACE_BASH+=	lsix

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/lsix ${DESTDIR}${PREFIX}/bin/lsix

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
