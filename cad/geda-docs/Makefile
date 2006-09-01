# $NetBSD: Makefile,v 1.18 2006/09/01 12:00:43 dmcmahill Exp $
#

DISTNAME=		geda-docs-${PKGVERSION}
CATEGORIES=		cad

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		HTML documentation for gEDA

DEPENDS+=		geda-symbols-${PKGVERSION}{,nb[0-9]*}:../../cad/geda-symbols
BUILD_DEPENDS+=		geda-symbols-${PKGVERSION}{,nb[0-9]*}:../../cad/geda-symbols

CONFLICTS+=		gEDA<19991011

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=		YES

.include "../../mk/bsd.pkg.mk"
