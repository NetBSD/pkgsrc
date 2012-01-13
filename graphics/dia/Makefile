# $NetBSD: Makefile,v 1.66 2012/01/13 10:55:10 obache Exp $
#

.include "Makefile.common"
PKGREVISION=		8

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
