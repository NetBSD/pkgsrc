# $NetBSD: Makefile,v 1.15 2004/02/23 04:01:58 dmcmahill Exp $
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

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=		YES

.include "../../mk/bsd.pkg.mk"
