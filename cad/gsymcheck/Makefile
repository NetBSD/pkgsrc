# $NetBSD: Makefile,v 1.30 2006/01/25 01:51:35 dmcmahill Exp $
#

DISTNAME=		geda-gsymcheck-${PKGVERSION}
PKGNAME=		gsymcheck-${PKGVERSION}
CATEGORIES=		cad

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		EDA (Electronic Design Automation) symbol checker

DEPENDS+=		geda-symbols-${PKGVERSION}:../../cad/geda-symbols

CONFLICTS+=		gEDA<19991011

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_TOOLS+=		pkg-config

.include "../../cad/libgeda/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
