# $NetBSD: Makefile,v 1.12 2003/09/10 23:43:34 dmcmahill Exp $
#

DISTNAME=	geda-symbols-${PKGVERSION}
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/devel/${PKGVERSION}/ \
		ftp://ieee.ing.uniroma1.it/pub/geda/devel/${PKGVERSION}/ \
		http://www.geda.seul.org/devel/${PKGVERSION}/ \
		http://www.geda.coelacanth.com/devel/${PKGVERSION}/

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.geda.seul.org/
COMMENT=	Library of symbols for gEDA

CONFLICTS+=	gEDA<19991011

DIST_SUBDIR=	geda
PKGVERSION=	20030901

GNU_CONFIGURE=	YES
USE_GMAKE=	YES

.include "../../mk/bsd.pkg.mk"
