# $NetBSD: Makefile,v 1.17 1999/04/15 20:39:42 tron Exp $

DISTNAME=		Wine-981211
PKGNAME=		wine-981211
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUNSITE:=ALPHA/wine/development/}
ONLY_FOR_ARCHS=		i386

MAINTAINER=		mycroft@netbsd.org
HOMEPAGE=		http://www.winehq.com/

DEPENDS+=		xpm-3.4k:../../graphics/xpm

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-dll

post-install:
	${INSTALL_DATA} ${WRKSRC}/wine.ini ${PREFIX}/etc/wine.conf.example

.include "../../mk/bsd.pkg.mk"
