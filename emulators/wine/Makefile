# $NetBSD: Makefile,v 1.19 1999/08/27 15:28:46 agc Exp $

DISTNAME=		Wine-981211
PKGNAME=		wine-981211
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUNSITE:=ALPHA/wine/development/}
ONLY_FOR_PLATFORM=	NetBSD-*-i386

MAINTAINER=		mycroft@netbsd.org
HOMEPAGE=		http://www.winehq.com/

DEPENDS+=		xpm-3.4k:../../graphics/xpm

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-dll

post-install:
	${INSTALL_DATA} ${WRKSRC}/wine.ini ${PREFIX}/etc/wine.conf.example

post-extract:
	@case `${MAKE} show-shlib-type` in				\
	ELF)	${ECHO} "Sorry, this package does not work with ELF object formats"; \
		${FALSE} ;;						\
	esac

.include "../../mk/bsd.pkg.mk"
