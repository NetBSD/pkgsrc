# $NetBSD: Makefile,v 1.33 2005/07/21 16:29:44 wiz Exp $
#

DISTNAME=		geda-gschem-${PKGVERSION}
PKGNAME=		gschem-${PKGVERSION}
CATEGORIES=		cad

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Schematic capture tool

DEPENDS+=		geda-symbols-${PKGVERSION}:../../cad/geda-symbols

CONFLICTS+=		gEDA<19991011

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
USE_MAKEINFO=		YES
INFO_FILES=		gschemdoc.info

.include "../../cad/libgeda/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libstroke/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
