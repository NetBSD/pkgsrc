# $NetBSD: Makefile,v 1.25 2006/05/18 20:29:58 wiz Exp $
#

DISTNAME=		twin-src-3.1.14
PKGNAME=		twin-3.1.14
PKGREVISION=		3
CATEGORIES=		emulators
MASTER_SITES=		ftp://ftp.willows.com/pub/twin/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.willows.com/
COMMENT=		Cross-platform implementation of the Win32 API

BROKEN_IN=		pkgsrc-2005Q4 pkgsrc-2006Q1

WRKSRC=			${WRKDIR}/twin
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
BUILD_TARGET=		depend world
CONFIGURE_ARGS+=	--enable-debugger

pre-build:
	${CP} ${WRKSRC}/windows/Execfreebsd.c ${WRKSRC}/windows/Execnetbsd.c

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/twin
	${INSTALL_DATA} ${WRKSRC}/documentation/* ${PREFIX}/share/doc/twin/
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/*.h.in ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/documentation/rc.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/documentation/debugger.1 ${PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/tools/rc/rc ${PREFIX}/bin

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
