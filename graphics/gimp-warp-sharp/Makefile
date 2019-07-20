# $NetBSD: Makefile,v 1.10 2019/07/20 19:38:14 tnn Exp $

DISTNAME=	warp-sharp
PKGNAME=	gimp-${DISTNAME}-1.5
CATEGORIES=	graphics
MASTER_SITES=	http://www.home.unix-ag.org/simon/gimp/
EXTRACT_SUFX=	.scm

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.home.unix-ag.org/simon/gimp/warp-sharp.html
COMMENT=	Image sharpening script for GIMP

DEPENDS+=	gimp>=2.0:../../graphics/gimp

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes

DIST_SUBDIR=	${PKGNAME_NOREV}

INSTALLATION_DIRS=	share/gimp/2.0/scripts

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}${EXTRACT_SUFX} \
		${DESTDIR}${PREFIX}/share/gimp/2.0/scripts

.include "../../mk/bsd.pkg.mk"
