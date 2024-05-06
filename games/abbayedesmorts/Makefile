# $NetBSD: Makefile,v 1.11 2024/05/06 14:37:14 nia Exp $

DISTNAME=	abbayedesmorts-gpl-2.0.2
PKGNAME=	${DISTNAME:S/-gpl//1}
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=nevat/}
GITHUB_PROJECT=	abbayedesmorts-gpl
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nevat/abbayedesmorts-gpl
COMMENT=	Obsolete video game for a dark passage of history
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake

# src/drawing.c:10: error: 'for' loop initial declaration used outside C99 mode
FORCE_C_STD=	gnu99

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
