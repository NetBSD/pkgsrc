# $NetBSD: Makefile,v 1.9 2001/02/16 13:30:54 wiz Exp $

DISTNAME=	xmradio-1.0
CATEGORIES=	audio
MASTER_SITES=	http://core.de/~coto/radio/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://core.de/~coto/xmradio.html
COMMENT=	Radio applicaton for Brooktree 848 compatible TV cards

DEPENDS+=	sox>=12.16:../sox

ONLY_FOR_PLATFORM=	NetBSD-1.4[Y-Z]-* NetBSD-1.4Z[A-Z]-i386 \
			NetBSD-1.5_ALPHA-i386 NetBSD-1.[5-9]*-*

USE_MOTIF=	YES
USE_IMAKE=	YES
USE_XPM=	YES

post-install:
	${MKDIR} ${PREFIX}/share/doc/xmradio
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xmradio

.include "../../mk/bsd.pkg.mk"
