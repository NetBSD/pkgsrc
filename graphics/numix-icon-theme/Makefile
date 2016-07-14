# $NetBSD: Makefile,v 1.1 2016/07/14 15:44:13 youri Exp $

GITHUB_PROJECT=	numix-icon-theme
GITHUB_TAG=	72c00cb61622e4a0c00243eda405746866dd82f9
DISTNAME=	numix-icon-theme-0.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=numixproject/}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/numixproject/numix-icon-theme/
COMMENT=	Numix icon theme
LICENSE=	gnu-gpl-v3

NO_BUILD=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	pax

INSTALLATION_DIRS=	share/icons

do-install:
	cd ${WRKSRC} && ${PAX} -rw Numix-Light Numix \
	${DESTDIR}${PREFIX}/share/icons/

.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
