# $NetBSD: Makefile,v 1.3 2003/09/02 23:38:24 jmc Exp $
#

DISTNAME=	artwiz-aleczapka-1.3
PKGNAME=        ${DISTNAME:S/aleczapka/fonts/}
CATEGORIES=	fonts
MASTER_SITES=	http://fluxbox.org/artwiz-aleczapka/
EXTRACT_SUFX=	.tar.bz2
WRKSRC=		${WRKDIR}/artwiz-aleczapka

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.vastwaters.com/
COMMENT=	Set of free fonts for X11 desktops

USE_BUILDLINK2=		yes
NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_X11BASE=		yes
USE_PKGINSTALL=		yes

FONTS= 			${PREFIX}/lib/X11/fonts/artwiz
FONTS_X11_DIRS=		${FONTS}
OWN_DIRS=		${FONTS}

do-install:
	for i in ${WRKSRC}/*.pcf; do ${INSTALL_DATA} $$i ${FONTS_X11_DIRS}; done

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
