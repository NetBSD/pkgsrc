# $NetBSD: Makefile,v 1.16 2005/01/11 03:16:22 dmcmahill Exp $
#

DISTNAME=		geda-docs-${PKGVERSION}
CATEGORIES=		cad

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		HTML documentation for gEDA

DEPENDS+=		geda-symbols-${PKGVERSION}:../../cad/geda-symbols
BUILD_DEPENDS+=		geda-symbols>=${PKGVERSION}:../../cad/geda-symbols

CONFLICTS+=		gEDA<19991011

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=		YES

.include "../../mk/bsd.pkg.mk"
