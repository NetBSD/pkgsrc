# $NetBSD: Makefile,v 1.5 1999/08/27 15:28:47 agc Exp $

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

post-extract:
	@case `${MAKE} show-shlib-type` in				\
	ELF)	${ECHO} "Sorry, this package does not work with ELF object formats"; \
		${FALSE} ;;						\
	esac

.include "../../mk/bsd.pkg.mk"
