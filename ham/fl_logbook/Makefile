# $NetBSD: Makefile,v 1.6 2012/10/03 13:01:43 asau Exp $
#

DISTNAME=		fl_logbook.121.src
PKGNAME=		fl_logbook-1.21
PKGREVISION=		2
CATEGORIES=		ham
MASTER_SITES=		http://www.w1hkj.com/LinuxApps/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.w1hkj.com/
COMMENT=		FLTK-based amateur radio log book

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV:C/-.*//}

USE_LANGUAGES=		c++
USE_TOOLS+=		gmake

MAKE_ENV+=		CFG=Release

BUILD_TARGET=		#defined in dist Makefile

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Release/fl_logbook ${DESTDIR}${PREFIX}/bin

.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
