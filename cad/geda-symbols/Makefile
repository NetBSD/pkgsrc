# $NetBSD: Makefile,v 1.4 2001/02/16 13:46:20 wiz Exp $
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
COMMENT=	Library of symbols for gEDA

CONFLICTS+=	gEDA<19991011

DIST_SUBDIR=	geda
PKGVERSION=	20000220

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

.include "../../mk/bsd.pkg.mk"
