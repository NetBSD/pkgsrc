# $NetBSD: Makefile,v 1.8 2000/08/23 15:33:40 wiz Exp $

DISTNAME=		Wine-990328
PKGNAME=		wine-990328
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUNSITE:=ALPHA/wine/development/}

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://www.winehq.com/

DEPENDS+=		xpm-3.4k:../../graphics/xpm
DEPENDS+=		ncurses>=4.2:../../devel/ncurses

ONLY_FOR_PLATFORM=	NetBSD-*-i386

USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-dll
CONFIGURE_ENV=		CC="${CC} -idirafter ${LOCALBASE}/include"
MAKE_ENV=		LDOPTIONS="${LDFLAGS}"
LDFLAGS=		-L${LOCALBASE}/lib

post-install:
	${INSTALL_DATA} ${WRKSRC}/wine.ini ${PREFIX}/etc/wine.conf.example

.include "../../mk/bsd.prefs.mk"

.if ${OBJECT_FMT} == "ELF"
BROKEN=			Does not work on ELF systems.
.endif

.include "../../mk/bsd.pkg.mk"
