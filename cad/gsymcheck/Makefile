# $NetBSD: Makefile,v 1.26 2005/04/11 21:45:02 tv Exp $
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

.include "../../cad/libgeda/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
