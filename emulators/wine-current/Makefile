# $NetBSD: Makefile,v 1.11 2001/12/26 20:10:31 wiz Exp $

DISTNAME=		Wine-990328
PKGNAME=		wine-990328
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUNSITE:=ALPHA/wine/development/}

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://www.winehq.com/
COMMENT=		Beta Windows (3.1x, 95, NT) emulator

ONLY_FOR_PLATFORM=	NetBSD-*-i386

GNU_CONFIGURE=		YES
CONFIGURE_ARGS=		--enable-dll
CONFIGURE_ENV=		CC="${CC} -idirafter ${BUILDLINK_DIR}/include"
MAKE_ENV=		LDOPTIONS="${LDFLAGS}"
USE_BUILDLINK_ONLY=	YES

# [n]curses' menu.h is found before wine's menu.h, but isn't needed anyway
post-configure:
	${RM} ${BUILDLINK_DIR}/include/menu.h

post-install:
	${INSTALL_DATA} ${WRKSRC}/wine.ini ${PREFIX}/etc/wine.conf.example

.include "../../mk/bsd.prefs.mk"

.if ${OBJECT_FMT} == "ELF"
BROKEN=			Does not work on ELF systems.
.endif

.include "../../devel/ncurses/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
