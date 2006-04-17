# $NetBSD: Makefile,v 1.47 2006/04/17 13:46:17 wiz Exp $
#

DISTNAME=	geda-${PKGVERSION}
PKGREVISION=	2
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
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		pkg-config

LTCONFIG_OVERRIDE=      ${WRKSRC}/ltconfig

.include "../../cad/libgeda/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
