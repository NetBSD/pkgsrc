# $NetBSD: Makefile,v 1.9 2003/03/09 06:18:24 dmcmahill Exp $
#

DISTNAME=	geda-symbols-${PKGVERSION}
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/devel/${PKGVERSION}/ \
		ftp://ieee.ing.uniroma1.it/pub/geda/devel/${PKGVERSION}/ \
		http://www.geda.seul.org/devel/${PKGVERSION}/ \
		http://www.geda.coelacanth.com/devel/${PKGVERSION}/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www.geda.seul.org/
COMMENT=	Library of symbols for gEDA

CONFLICTS+=	gEDA<19991011

DIST_SUBDIR=	geda
PKGVERSION=	20030223

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
USE_GMAKE=	YES

.include "../../mk/bsd.pkg.mk"
