# $NetBSD: Makefile,v 1.16 2002/09/21 21:07:03 jlam Exp $

DISTNAME=	xmradio-1.2
CATEGORIES=	audio
MASTER_SITES=	http://core.de/~coto/radio/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://core.de/~coto/xmradio.html
COMMENT=	Radio applicaton for Brooktree 848 compatible TV cards

DEPENDS+=	sox>=12.16:../../audio/sox

ONLY_FOR_PLATFORM=	NetBSD-1.4[Y-Z]-* NetBSD-1.4Z[A-Z]-i386 \
			NetBSD-1.5_ALPHA-i386 NetBSD-1.[5-9]*-*

USE_BUILDLINK2=	YES
USE_IMAKE=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xmradio
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/xmradio

.include "../../graphics/xpm/buildlink2.mk"
.include "../../mk/motif.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
