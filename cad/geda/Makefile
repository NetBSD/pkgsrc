# $NetBSD: Makefile,v 1.38 2005/01/11 03:16:22 dmcmahill Exp $
#

DISTNAME=	geda-${PKGVERSION}
CATEGORIES=	cad

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://www.geda.seul.org/
COMMENT=	Toolset for automating electronic design

DEPENDS+=	gattrib-${PKGVERSION}{,nb[0-9]*}:../../cad/gattrib
DEPENDS+=	gschem-${PKGVERSION}{,nb[0-9]*}:../../cad/gschem
DEPENDS+=	gnetlist-${PKGVERSION}{,nb[0-9]*}:../../cad/gnetlist
DEPENDS+=	gsymcheck-${PKGVERSION}{,nb[0-9]*}:../../cad/gsymcheck
DEPENDS+=	geda-utils-${PKGVERSION}{,nb[0-9]*}:../../cad/geda-utils
DEPENDS+=	geda-docs-${PKGVERSION}{,nb[0-9]*}:../../cad/geda-docs
DEPENDS+=	geda-examples-${PKGVERSION}{,nb[0-9]*}:../../cad/geda-examples

.include "Makefile.common"

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK3=		YES

LTCONFIG_OVERRIDE=      ${WRKSRC}/ltconfig

.include "../../cad/libgeda/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
