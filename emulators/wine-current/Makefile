# $NetBSD: Makefile,v 1.6 1999/12/29 01:47:59 wiz Exp $

DISTNAME=		Wine-990328
PKGNAME=		wine-990328
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUNSITE:=ALPHA/wine/development/}

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://www.winehq.com/

DEPENDS+=		xpm-3.4k:../../graphics/xpm
DEPENDS+=		ncurses-4.2:../../devel/ncurses

ONLY_FOR_PLATFORM=	NetBSD-*-i386

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
