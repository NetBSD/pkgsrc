# $NetBSD: Makefile,v 1.4 2002/12/24 18:55:38 wiz Exp $
#

DISTNAME=		twin-src-3.1.14
PKGNAME=		twin-3.1.14
CATEGORIES=		emulators
MASTER_SITES=		ftp://ftp.willows.com/pub/twin/

MAINTAINER=		collver1@attbi.com
HOMEPAGE=		http://www.willows.com
COMMENT=		cross-platform implementation of the win32 api

GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes
WRKSRC=			${WRKDIR}/twin
ALL_TARGET=		depend world
AUTOCONF_REQD=		2.13

pre-configure:
	cd ${WRKSRC} && ${AUTORECONF} --force

pre-build:
	${CP} ${WRKSRC}/windows/Execfreebsd.c ${WRKSRC}/windows/Execnetbsd.c

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/twin
	${INSTALL_DATA} ${WRKSRC}/documentation/* ${PREFIX}/share/doc/twin/
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/documentation/rc.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/documentation/debugger.1 ${PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/tools/rc/rc ${PREFIX}/bin

.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
