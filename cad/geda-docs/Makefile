# $NetBSD: Makefile,v 1.14 2003/09/10 23:43:33 dmcmahill Exp $
#

DISTNAME=		geda-docs-${PKGVERSION}
CATEGORIES=		cad
MASTER_SITES=		ftp://ftp.geda.seul.org/pub/geda/devel/${PKGVERSION}/ \
			ftp://ieee.ing.uniroma1.it/pub/geda/devel/${PKGVERSION}/ \
			http://www.geda.seul.org/devel/${PKGVERSION}/ \
			http://www.geda.coelacanth.com/devel/${PKGVERSION}/

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		HTML documentation for gEDA

DEPENDS+=		geda-symbols-${PKGVERSION}:../../cad/geda-symbols
BUILD_DEPENDS+=		geda-symbols>=${PKGVERSION}:../../cad/geda-symbols

CONFLICTS+=		gEDA<19991011

DIST_SUBDIR=		geda
PKGVERSION=		20030901

GNU_CONFIGURE=		YES

.include "../../mk/bsd.pkg.mk"
