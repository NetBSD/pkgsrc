# $NetBSD: Makefile,v 1.12 2003/07/15 09:23:32 dmcmahill Exp $
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

DEPENDS+=		geda-symbols-${PKGVERSION}:../../cad/geda-symbols

CONFLICTS+=		gEDA<19991011

BUILD_DEPENDS+=		geda-symbols>=${PKGVERSION}:../../cad/geda-symbols

DIST_SUBDIR=		geda
PKGVERSION=		20030525

GNU_CONFIGURE=		YES
USE_X11BASE=		YES

.include "../../mk/bsd.pkg.mk"
