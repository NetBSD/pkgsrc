# $NetBSD: Makefile,v 1.10 2004/01/05 22:44:04 jlam Exp $
#

DISTNAME=		SDL_mixer-1.2.5
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		http://www.libsdl.org/projects/SDL_mixer/release/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.libsdl.org/projects/SDL_mixer/
COMMENT=		Multi-channel audio mixer library

CONFLICTS=		SDL-mixer-[0-9]*

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_X11=		YES
USE_LIBTOOL=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

CPPFLAGS=		-Dunix=1
CFLAGS=			-DPREFIX=\"\\\"${PREFIX}\\\"\"

INSTALLATION_DIRS=	bin

post-install:
	${PKGLIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/playmus ${PREFIX}/bin
	${PKGLIBTOOL} ${INSTALL_PROGRAM} ${WRKSRC}/playwave ${PREFIX}/bin

.include "../../audio/libogg/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/smpeg/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
