# $NetBSD: Makefile,v 1.13 2007/02/22 19:26:29 wiz Exp $
#

DISTNAME=	artwiz-aleczapka-1.3
PKGNAME=	${DISTNAME:S/aleczapka/fonts/}
PKGREVISION=	3
CATEGORIES=	fonts
MASTER_SITES=	http://fluxbox.org/artwiz-aleczapka/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.vastwaters.com/
COMMENT=	Set of free fonts for X11 desktops

WRKSRC=		${WRKDIR}/artwiz-aleczapka
USE_X11BASE=	yes

NO_BUILD=	yes
NO_CONFIGURE=	yes

FONTS_DIRS.x11=	${PREFIX}/lib/X11/fonts/artwiz
REQD_DIRS=	${PREFIX}/lib/X11/fonts/artwiz

do-install:
	for i in ${WRKSRC}/*.pcf; do ${INSTALL_DATA} $$i ${FONTS_DIRS.x11}; done

.include "../../mk/bsd.pkg.mk"
