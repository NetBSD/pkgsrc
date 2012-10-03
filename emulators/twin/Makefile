# $NetBSD: Makefile,v 1.33 2012/10/03 12:55:19 asau Exp $
#

DISTNAME=		twin-src-3.1.14
PKGNAME=		twin-3.1.14
PKGREVISION=		4
CATEGORIES=		emulators
MASTER_SITES=		ftp://ftp.willows.com/pub/twin/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.willows.com/
COMMENT=		Cross-platform implementation of the Win32 API
LICENSE=		gnu-lgpl-v2

WRKSRC=			${WRKDIR}/twin
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake lex yacc
BUILD_TARGET=		depend world
CONFIGURE_ARGS+=	--disable-debugger

MAKE_JOBS_SAFE=		no

NOT_FOR_PLATFORM=	*-*-x86_64

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}

INSTALLATION_DIRS+=	share/doc/twin
INSTALLATION_DIRS+=	include
INSTALLATION_DIRS+=	${PKGMANDIR}/man1

pre-build:
	${CP} ${WRKSRC}/windows/Execfreebsd.c ${WRKSRC}/windows/Execnetbsd.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/documentation/* ${DESTDIR}${PREFIX}/share/doc/twin/
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${DESTDIR}${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/include/*.h.in ${DESTDIR}${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/documentation/rc.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_PROGRAM} ${WRKSRC}/tools/rc/rc ${DESTDIR}${PREFIX}/bin

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
