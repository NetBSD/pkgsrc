# $NetBSD: Makefile,v 1.4 2000/06/01 11:23:15 rh Exp $
#

DISTNAME=		gsymcheck-${PKGVERSION}
WRKSRC=			${WRKDIR}/gsymcheck
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
PKGVERSION=		20000220

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_PKGLIBTOOL=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
