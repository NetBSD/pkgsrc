# $NetBSD: Makefile,v 1.2 2021/09/08 21:05:03 nia Exp $

DISTNAME=	abbayedesmorts-gpl-2.0.1
PKGNAME=	${DISTNAME:S/-gpl//1}
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=nevat/}
GITHUB_PROJECT=	abbayedesmorts-gpl
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nevat/abbayedesmorts-gpl
COMMENT=	Obsolete video game for a dark passage of history
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
