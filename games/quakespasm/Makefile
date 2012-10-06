# $NetBSD: Makefile,v 1.2 2012/10/06 11:54:52 asau Exp $

DISTNAME=	quakespasm-0.85.1
CATEGORIES=	games x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=quakespasm/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://quakespasm.sourceforge.net/
COMMENT=	Enhanced Quake engine using SDL

# needs fm{ax,in}, which NetBSD doesn't have prior to 5.1
NOT_FOR_PLATFORM=	NetBSD-4*-* NetBSD-5.0*-*

USE_TOOLS+=	gmake

INSTALLATION_DIRS=	bin

WRKSRC=		${WRKDIR}/${DISTNAME}/Quake

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/quakespasm ${DESTDIR}${PREFIX}/bin

.include "../../net/SDL_net/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
