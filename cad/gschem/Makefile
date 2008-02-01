# $NetBSD: Makefile,v 1.44 2008/02/01 02:34:22 dmcmahill Exp $
#

DISTNAME=		geda-gschem-${PKGVERSION}
PKGNAME=		gschem-${PKGVERSION}
CATEGORIES=		cad

MAINTAINER=		dmcmahill@NetBSD.org
HOMEPAGE=		http://www.geda.seul.org/
COMMENT=		Schematic capture tool

DEPENDS+=		geda-symbols-${PKGVERSION}{,nb[0-9]*}:../../cad/geda-symbols
DEPENDS+=		gettext-tools>=0.14.6:../../devel/gettext-tools

CONFLICTS+=		gEDA<19991011

.include "../../cad/geda/Makefile.common"

GNU_CONFIGURE=		YES
USE_TOOLS+=		bash intltool msgfmt pkg-config
# otherwise the gettext stuff in here tries to do
# /bin/sh /usr/bin/install -d /some/directory
# but of course /usr/bin/install is a binary.
MAKE_FLAGS+=		install_sh=${WRKSRC}/install-sh
CONFIGURE_ARGS+=	--disable-update-desktop-database
CONFIGURE_ARGS+=	--disable-update-mime-database

REPLACE_BASH=		icon-theme-installer

.include "../../cad/libgeda/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/libstroke/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
