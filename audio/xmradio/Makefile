# $NetBSD: Makefile,v 1.21 2004/10/03 00:13:12 tv Exp $

DISTNAME=	xmradio-1.2
PKGREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://core.de/~coto/radio/

MAINTAINER=	hubertf@NetBSD.org
HOMEPAGE=	http://core.de/~coto/xmradio.html
COMMENT=	Radio application for Brooktree 848 compatible TV cards

DEPENDS+=	sox>=12.16:../../audio/sox

ONLY_FOR_PLATFORM=	NetBSD-1.4[Y-Z]-* NetBSD-1.4Z[A-Z]-i386 \
			NetBSD-1.5_ALPHA-i386 NetBSD-1.[5-9]*-* \
			NetBSD-[2-9]*.*-*

USE_BUILDLINK3=	YES
USE_IMAKE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xmradio
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xmradio

.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
