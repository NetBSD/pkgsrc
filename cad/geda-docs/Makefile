# $NetBSD: Makefile,v 1.17 2006/02/05 23:08:21 joerg Exp $
#

DISTNAME=		geda-docs-${PKGVERSION}
PKGREVISION=		1
CATEGORIES=		cad

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		HTML documentation for gEDA

DEPENDS+=		geda-symbols-${PKGVERSION}nb1:../../cad/geda-symbols
BUILD_DEPENDS+=		geda-symbols>=${PKGVERSION}:../../cad/geda-symbols

CONFLICTS+=		gEDA<19991011

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=		YES

.include "../../mk/bsd.pkg.mk"
