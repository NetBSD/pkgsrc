# $NetBSD: Makefile,v 1.30 2009/08/25 12:32:55 wiz Exp $
#

DISTNAME=		twin-src-3.1.14
PKGNAME=		twin-3.1.14
PKGREVISION=		3
CATEGORIES=		emulators
MASTER_SITES=		ftp://ftp.willows.com/pub/twin/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.willows.com/
COMMENT=		Cross-platform implementation of the Win32 API

WRKSRC=			${WRKDIR}/twin
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake lex yacc
BUILD_TARGET=		depend world
CONFIGURE_ARGS+=	--enable-debugger

pre-build:
	${CP} ${WRKSRC}/windows/Execfreebsd.c ${WRKSRC}/windows/Execnetbsd.c

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/twin
	${INSTALL_DATA} ${WRKSRC}/documentation/* ${PREFIX}/share/doc/twin/
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/*.h.in ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/documentation/rc.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/documentation/debugger.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/tools/rc/rc ${PREFIX}/bin

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
