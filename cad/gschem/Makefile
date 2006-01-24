# $NetBSD: Makefile,v 1.35 2006/01/24 07:31:56 wiz Exp $
#

DISTNAME=		geda-gschem-${PKGVERSION}
PKGNAME=		gschem-${PKGVERSION}
PKGREVISION=		1
CATEGORIES=		cad

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Schematic capture tool

DEPENDS+=		geda-symbols-${PKGVERSION}:../../cad/geda-symbols

CONFLICTS+=		gEDA<19991011

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=		YES
USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	YES
USE_MAKEINFO=		YES
INFO_FILES=		gschemdoc.info

.include "../../cad/libgeda/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libstroke/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
