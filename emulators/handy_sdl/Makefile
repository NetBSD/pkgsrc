# $NetBSD: Makefile,v 1.4 2010/02/14 18:42:53 joerg Exp $
#

DISTNAME=	handy_sdl-0.5-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	emulators
MASTER_SITES=	http://www.xs4all.nl/~shalafi/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sdlemu.ngemu.com/handysdl.php
COMMENT=	Atari Lynx emulator

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=		no

MAKE_FILE=	Makefile-0.95
USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin share/doc/handy_sdl

post-extract:
	${CHMOD} -R a+X ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/handy_sdl ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/handy_sdl

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
