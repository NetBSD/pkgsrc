# $NetBSD: Makefile,v 1.1.1.1 2003/08/30 14:23:41 xtraeme Exp $
#

DISTNAME=	artwiz-aleczapka
PKGNAME=        artwiz-fonts-1.0
CATEGORIES=	fonts
MASTER_SITES=	http://fluxbox.org/artwiz-aleczapka/
EXTRACT_SUFX=	.tar.bz2

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
	${INSTALL_DATA} ${WRKSRC}/*.pcf ${FONTS_X11_DIRS}

.include "../../mk/fonts.mk"
.include "../../mk/bsd.pkg.mk"
