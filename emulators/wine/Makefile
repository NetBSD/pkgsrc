# $NetBSD: Makefile,v 1.13 1998/11/12 23:20:09 frueauf Exp $

DISTNAME=		Wine-980614
PKGNAME=		wine-980614
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	ALPHA/wine/development
ONLY_FOR_ARCHS=		i386

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://www.winehq.com/

DEPENDS+=       xpm-3.4k:../../graphics/xpm

CONFLICTS=	wine-980215

USE_X11=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --enable-dll

post-install:
	${INSTALL_DATA} ${WRKSRC}/wine.ini ${PREFIX}/etc/wine.conf.example

.include "../../mk/bsd.pkg.mk"
