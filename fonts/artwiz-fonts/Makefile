# $NetBSD: Makefile,v 1.5 2004/01/20 12:15:17 agc Exp $
#

DISTNAME=	artwiz-aleczapka-1.3
PKGNAME=        ${DISTNAME:S/aleczapka/fonts/}
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	http://fluxbox.org/artwiz-aleczapka/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.vastwaters.com/
COMMENT=	Set of free fonts for X11 desktops

WRKSRC=			${WRKDIR}/artwiz-aleczapka
USE_BUILDLINK2=		yes
USE_X11BASE=		yes
USE_PKGINSTALL=		yes

NO_BUILD=		yes
NO_CONFIGURE=		yes

FONTS_X11_DIRS=		${PREFIX}/lib/X11/fonts/artwiz
OWN_DIRS=		${PREFIX}/lib/X11/fonts/artwiz

do-install:
	for i in ${WRKSRC}/*.pcf; do ${INSTALL_DATA} $$i ${FONTS_X11_DIRS}; done

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
