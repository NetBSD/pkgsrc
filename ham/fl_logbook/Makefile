# $NetBSD: Makefile,v 1.4 2010/06/13 22:44:47 wiz Exp $
#

DISTNAME=		fl_logbook.121.src
PKGNAME=		fl_logbook-1.21
PKGREVISION=		1
CATEGORIES=		ham
MASTER_SITES=		http://www.w1hkj.com/LinuxApps/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.w1hkj.com/
COMMENT=		FLTK-based amateur radio log book

PKG_DESTDIR_SUPPORT=	user-destdir

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
