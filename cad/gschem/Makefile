# $NetBSD: Makefile,v 1.38 2006/03/05 16:27:23 jlam Exp $
#

DISTNAME=		geda-gschem-${PKGVERSION}
PKGNAME=		gschem-${PKGVERSION}
PKGREVISION=		1
CATEGORIES=		cad

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Schematic capture tool

DEPENDS+=		geda-symbols-${PKGVERSION}nb1:../../cad/geda-symbols

CONFLICTS+=		gEDA<19991011

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=		YES
USE_TOOLS+=		makeinfo pkg-config
USE_PKGLOCALEDIR=	YES
INFO_FILES=		gschemdoc.info

.include "../../cad/libgeda/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libstroke/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
