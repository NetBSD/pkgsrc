# $NetBSD: Makefile,v 1.1 2016/07/14 15:31:21 youri Exp $

GITHUB_PROJECT=	numix-icon-theme-circle
GITHUB_TAG=	ae60ceabef8e25bf8fdea0196eecb004d4ef4483
DISTNAME=	numix-icon-theme-circle-0.1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=numixproject/}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/numixproject/numix-icon-theme-circle/
COMMENT=	Numix Circle icon theme
LICENSE=	gnu-gpl-v3

NO_BUILD=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	pax

INSTALLATION_DIRS=	share/icons

do-install:
	cd ${WRKSRC} && ${PAX} -rw Numix-Circle-Light Numix-Circle \
	${DESTDIR}${PREFIX}/share/icons/

.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
