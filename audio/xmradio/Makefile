# $NetBSD: Makefile,v 1.3 2000/06/05 07:28:47 tron Exp $

DISTNAME=	xmradio-0.9b2
CATEGORIES=	audio
MASTER_SITES=	http://www.rostock.zgdv.de/~runge/radio/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.rostock.zgdv.de/~runge/xmradio.html

DEPENDS+=	sox>=12.16:../sox
DEPENDS+=	xpm-3.4k:../../graphics/xpm

ONLY_FOR_PLATFORM=	NetBSD-1.4[Y-Z]-* NetBSD-1.4Z[A-Z]-i386 \
			NetBSD-1.[5-9]*-*

USE_MOTIF=	yes
USE_IMAKE=	yes

post-install:
	${MKDIR} ${PREFIX}/share/doc/xmradio
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xmradio

.include "../../mk/bsd.pkg.mk"
