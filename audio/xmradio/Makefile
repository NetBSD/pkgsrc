# $NetBSD: Makefile,v 1.5 2000/08/23 23:14:22 tron Exp $

DISTNAME=	xmradio-0.9b2
CATEGORIES=	audio
MASTER_SITES=	http://www.rostock.zgdv.de/~runge/radio/

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.rostock.zgdv.de/~runge/xmradio.html

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
