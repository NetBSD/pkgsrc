# $NetBSD: Makefile,v 1.1.1.1 2000/01/02 22:05:39 rh Exp $
#

DISTNAME=	symbols-${PKGVERSION}
PKGNAME=	geda-${DISTNAME}
WRKSRC=		${WRKDIR}/symbols
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/devel/${PKGVERSION}/ \
		ftp://ieee.ing.uniroma1.it/pub/geda/devel/${PKGVERSION}/ \
		http://www.geda.seul.org/devel/${PKGVERSION}/ \
		http://www.geda.coelacanth.com/devel/${PKGVERSION}/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.geda.seul.org/

DIST_SUBDIR=	geda
PKGVERSION=	19991011

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

.include "../../mk/bsd.pkg.mk"
