# $NetBSD: Makefile,v 1.2 2000/01/02 23:28:35 rh Exp $
#

DISTNAME=		utils-${PKGVERSION}
PKGNAME=		geda-${DISTNAME}
WRKSRC=			${WRKDIR}/utils
CATEGORIES=		cad
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/${PKGVERSION}/ \
			ftp://ieee.ing.uniroma1.it/pub/geda/devel/${PKGVERSION}/ \
			http://www.geda.seul.org/devel/${PKGVERSION}/ \
			http://www.geda.coelacanth.com/devel/${PKGVERSION}/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.geda.seul.org/

DEPENDS+=		libgeda-${PKGVERSION}:../../cad/libgeda

CONFLICTS+=		gEDA<19991011

DIST_SUBDIR=		geda
PKGVERSION=		19991011

GNU_CONFIGURE=		YES
USE_X11BASE=		YES

.include "../../mk/bsd.pkg.mk"
