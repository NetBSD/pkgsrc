# $NetBSD: Makefile,v 1.5.2.1 2002/06/23 18:39:51 jlam Exp $
#

DISTNAME=	geda-symbols-${PKGVERSION}
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
PKGVERSION=	20020414

GNU_CONFIGURE=	YES
USE_X11BASE=	YES

.include "../../mk/bsd.pkg.mk"
