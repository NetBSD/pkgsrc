# $NetBSD: Makefile,v 1.1.1.1 2004/11/07 15:06:08 minskim Exp $

DISTNAME=	warp-sharp
PKGNAME=	gimp-${DISTNAME}-1.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.home.unix-ag.org/simon/gimp/
EXTRACT_SUFX=	.scm

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.home.unix-ag.org/simon/gimp/warp-sharp.html
COMMENT=	Image sharpening script for GIMP

DEPENDS=	gimp>=2.0:../../graphics/gimp

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes

DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX} \
		${PREFIX}/share/gimp/2.0/scripts

.include "../../mk/bsd.pkg.mk"
