# $NetBSD: Makefile,v 1.15 1999/01/30 23:18:46 agc Exp $

DISTNAME=		Wine-981211
PKGNAME=		wine-981211
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	ALPHA/wine/development
ONLY_FOR_ARCHS=		i386

MAINTAINER=		mycroft@netbsd.org
HOMEPAGE=		http://www.winehq.com/

DEPENDS+=		xpm-3.4k:../../graphics/xpm

CONFLICTS=		wine-980[26]*

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-dll

post-install:
	${INSTALL_DATA} ${WRKSRC}/wine.ini ${PREFIX}/etc/wine.conf.example

.include "../../mk/bsd.pkg.mk"
