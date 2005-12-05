# $NetBSD: Makefile,v 1.19 2005/12/05 20:50:12 rillig Exp $
#

DISTNAME=		twin-src-3.1.14
PKGNAME=		twin-3.1.14
PKGREVISION=		2
CATEGORIES=		emulators
MASTER_SITES=		ftp://ftp.willows.com/pub/twin/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.willows.com/
COMMENT=		Cross-platform implementation of the win32 api

WRKSRC=			${WRKDIR}/twin
GNU_CONFIGURE=		yes
USE_TOOLS+=		autoconf213 gmake
BUILD_TARGET=		depend world
CONFIGURE_ARGS+=	--enable-debugger

.include "../../mk/x11.buildlink3.mk"

pre-configure:
	cd ${WRKSRC} && autoreconf --force

pre-build:
	${CP} ${WRKSRC}/windows/Execfreebsd.c ${WRKSRC}/windows/Execnetbsd.c

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/twin
	${INSTALL_DATA} ${WRKSRC}/documentation/* ${PREFIX}/share/doc/twin/
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/documentation/rc.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/documentation/debugger.1 ${PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/tools/rc/rc ${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
