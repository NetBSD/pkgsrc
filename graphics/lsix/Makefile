# $NetBSD: Makefile,v 1.27 2024/06/23 03:42:34 wiz Exp $

DISTNAME=	lsix-1.8.2
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=hackerb9/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hackerb9/lsix/
COMMENT=	Like ls, but for images
LICENSE=	gnu-gpl-v3

DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

USE_TOOLS+=	bash:run
USE_LANGUAGES=	# none
NO_BUILD=	yes
REPLACE_BASH+=	lsix

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/lsix ${DESTDIR}${PREFIX}/bin/lsix

.include "../../mk/bsd.pkg.mk"
