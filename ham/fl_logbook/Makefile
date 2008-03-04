# $NetBSD: Makefile,v 1.2 2008/03/04 15:51:59 jlam Exp $
#

DISTNAME=		fl_logbook.121.src
PKGNAME=		fl_logbook-1.21
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

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Release/fl_logbook ${DESTDIR}${PREFIX}/bin

.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
