# $NetBSD: Makefile,v 1.1.1.1 2000/05/07 20:34:13 tron Exp $

DISTNAME=	fxtv-1.02
CATEGORIES=	graphics
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.ipass.net/~dbhopper/aa8vb/fxtv/

DEPENDS+=	tiff>=3.5.5:../../graphics/tiff
DEPENDS+=	xpm-3.4[j-z]:../../graphics/xpm

ONLY_FOR_PLATFORM=	NetBSD-1.4[Y-Z]-* NetBSD-1.[5-9]*-*

USE_GMAKE=	yes
USE_XAW=	yes
USE_X11BASE=	yes

post-extract:
	@${RM} -f ${WRKSRC}/videolib/videolib.o

.include "../../mk/bsd.pkg.mk"
