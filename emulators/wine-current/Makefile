# $NetBSD: Makefile,v 1.10 2001/02/17 18:38:34 wiz Exp $

DISTNAME=		Wine-990328
PKGNAME=		wine-990328
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUNSITE:=ALPHA/wine/development/}

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://www.winehq.com/
COMMENT=		Beta Windows (3.1x, 95, NT) emulator

DEPENDS+=		ncurses>=4.2:../../devel/ncurses

ONLY_FOR_PLATFORM=	NetBSD-*-i386

USE_X11=		YES
USE_XPM=		YES
GNU_CONFIGURE=		YES
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
