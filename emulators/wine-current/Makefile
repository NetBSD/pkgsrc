# $NetBSD: Makefile,v 1.4 1999/07/06 08:01:26 jlam Exp $

DISTNAME=		Wine-990328
PKGNAME=		wine-990328
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUNSITE:=ALPHA/wine/development/}
ONLY_FOR_PLATFORM=	NetBSD-*-i386

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://www.winehq.com/

DEPENDS+=		xpm-3.4k:../../graphics/xpm
DEPENDS+=		ncurses-4.2:../../devel/ncurses

USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-dll
CONFIGURE_ENV=		CC="${CC} -idirafter ${LOCALBASE}/include"
MAKE_ENV=		LDOPTIONS="${LDFLAGS}"
LDFLAGS=		-L${LOCALBASE}/lib

post-install:
	${INSTALL_DATA} ${WRKSRC}/wine.ini ${PREFIX}/etc/wine.conf.example

.include "../../mk/bsd.pkg.mk"
