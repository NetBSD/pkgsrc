# $NetBSD: Makefile,v 1.2 2000/01/02 23:28:36 rh Exp $
#

DISTNAME=		gschem-${PKGVERSION}
WRKSRC=			${WRKDIR}/gschem
CATEGORIES=		cad
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/${PKGVERSION}/ \
			ftp://ieee.ing.uniroma1.it/pub/geda/devel/${PKGVERSION}/ \
			http://www.geda.seul.org/devel/${PKGVERSION}/ \
			http://www.geda.coelacanth.com/devel/${PKGVERSION}/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.geda.seul.org/

DEPENDS+=		libgeda-${PKGVERSION}:../../cad/libgeda
DEPENDS+=		geda-symbols-${PKGVERSION}:../../cad/geda-symbols

CONFLICTS+=		gEDA<19991011

DIST_SUBDIR=		geda
PKGVERSION=		19991011

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
