# $NetBSD: Makefile,v 1.21 2000/08/23 15:33:39 wiz Exp $

DISTNAME=		Wine-981211
PKGNAME=		wine-981211
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUNSITE:=ALPHA/wine/development/}

MAINTAINER=		mycroft@netbsd.org
HOMEPAGE=		http://www.winehq.com/

DEPENDS+=		xpm-3.4k:../../graphics/xpm

ONLY_FOR_PLATFORM=	NetBSD-*-i386

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-dll

post-install:
	${INSTALL_DATA} ${WRKSRC}/wine.ini ${PREFIX}/etc/wine.conf.example

.include "../../mk/bsd.prefs.mk"

.if ${OBJECT_FMT} == "ELF"
BROKEN=			Does not work on ELF systems.
.endif

.include "../../mk/bsd.pkg.mk"
