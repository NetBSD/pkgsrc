# $NetBSD: Makefile,v 1.13 2004/12/03 15:14:56 wiz Exp $
#

DISTNAME=		twin-src-3.1.14
PKGNAME=		twin-3.1.14
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		ftp://ftp.willows.com/pub/twin/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.willows.com/
COMMENT=		Cross-platform implementation of the win32 api

WRKSRC=			${WRKDIR}/twin
GNU_CONFIGURE=		yes
USE_GNU_TOOLS+=		make
USE_X11=		yes
BUILD_TARGET=		depend world
AUTOCONF_REQD=		2.13
CONFIGURE_ARGS=		--enable-debugger
PLIST_SRC=		${WRKDIR}/PLIST

pre-configure:
	cd ${WRKSRC} && ${AUTORECONF} --force

pre-build:
	${CP} ${WRKSRC}/windows/Execfreebsd.c ${WRKSRC}/windows/Execnetbsd.c

pre-install:
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
.if exists(${PKGDIR}/PLIST.${MACHINE_ARCH})
	@${CAT} ${PKGDIR}/PLIST.${MACHINE_ARCH} >> ${PLIST_SRC}
.endif

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/twin
	${INSTALL_DATA} ${WRKSRC}/documentation/* ${PREFIX}/share/doc/twin/
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/documentation/rc.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/documentation/debugger.1 ${PREFIX}/man/man1
	${INSTALL_PROGRAM} ${WRKSRC}/tools/rc/rc ${PREFIX}/bin

.include "../../mk/autoconf.mk"
.include "../../mk/bsd.pkg.mk"
