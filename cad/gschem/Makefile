# $NetBSD: Makefile,v 1.43 2007/05/31 12:48:32 dmcmahill Exp $
#

DISTNAME=		geda-gschem-${PKGVERSION}
PKGNAME=		gschem-${PKGVERSION}
CATEGORIES=		cad

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Schematic capture tool

DEPENDS+=		geda-symbols-${PKGVERSION}{,nb[0-9]*}:../../cad/geda-symbols

CONFLICTS+=		gEDA<19991011

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=		YES
USE_TOOLS+=		pkg-config
# otherwise the gettext stuff in here tries to do
# /bin/sh /usr/bin/install -d /some/directory
# but of course /usr/bin/install is a binary.
MAKE_FLAGS+=		install_sh=${WRKSRC}/install-sh
USE_PKGLOCALEDIR=	YES

.include "../../cad/libgeda/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libstroke/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
