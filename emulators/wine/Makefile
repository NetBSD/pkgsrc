# $NetBSD: Makefile,v 1.23 2001/02/17 18:38:33 wiz Exp $

DISTNAME=		Wine-981211
PKGNAME=		wine-981211
WRKSRC=			${WRKDIR}/${PKGNAME}
CATEGORIES=		emulators
MASTER_SITES=		${MASTER_SITE_SUNSITE:=ALPHA/wine/development/}

MAINTAINER=		mycroft@netbsd.org
HOMEPAGE=		http://www.winehq.com/
COMMENT=		Beta Windows (3.1x, 95, NT) emulator

ONLY_FOR_PLATFORM=	NetBSD-*-i386

USE_X11BASE=		YES
USE_XPM=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--enable-dll

post-install:
	${INSTALL_DATA} ${WRKSRC}/wine.ini ${PREFIX}/etc/wine.conf.example

.include "../../mk/bsd.prefs.mk"

.if ${OBJECT_FMT} == "ELF"
BROKEN=			Does not work on ELF systems.
.endif

.include "../../mk/bsd.pkg.mk"
