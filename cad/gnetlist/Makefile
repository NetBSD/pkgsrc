# $NetBSD: Makefile,v 1.8 2002/03/13 17:36:39 fredb Exp $
#

DISTNAME=		geda-gnetlist-${PKGVERSION}
PKGNAME=		gnetlist-${PKGVERSION}
PKGREVISION=		1
CATEGORIES=		cad
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/${PKGVERSION}/ \
			ftp://ieee.ing.uniroma1.it/pub/geda/devel/${PKGVERSION}/ \
			http://www.geda.seul.org/devel/${PKGVERSION}/ \
			http://www.geda.coelacanth.com/devel/${PKGVERSION}/

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Netlist generation program

DIST_SUBDIR=		geda
PKGVERSION=		20010708

DEPENDS+=		libgeda-${PKGVERSION}nb1:../../cad/libgeda
DEPENDS+=		geda-symbols-${PKGVERSION}:../../cad/geda-symbols

CONFLICTS+=		gEDA<19991011

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
