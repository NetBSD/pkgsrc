# $NetBSD: Makefile,v 1.9 2002/12/26 18:17:19 jschauma Exp $
#

DISTNAME=		geda-docs-${PKGVERSION}
CATEGORIES=		cad
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/${PKGVERSION}/ \
			ftp://ieee.ing.uniroma1.it/pub/geda/devel/${PKGVERSION}/ \
			http://www.geda.seul.org/devel/${PKGVERSION}/ \
			http://www.geda.coelacanth.com/devel/${PKGVERSION}/

MAINTAINER=		dmcmahill@netbsd.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		HTML documentation for gEDA

CONFLICTS+=		gEDA<19991011

BUILD_DEPENDS+=		geda-symbols>=${PKGVERSION}:../../cad/geda-symbols

DIST_SUBDIR=		geda
PKGVERSION=		20021103

GNU_CONFIGURE=		YES
USE_X11BASE=		YES

.include "../../mk/bsd.pkg.mk"
