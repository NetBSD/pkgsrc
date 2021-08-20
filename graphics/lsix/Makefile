# $NetBSD: Makefile,v 1.3 2021/08/20 11:23:44 pin Exp $

DISTNAME=	lsix-1.8
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
