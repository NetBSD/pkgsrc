# $NetBSD: Makefile,v 1.63 2011/04/22 13:43:42 obache Exp $
#

.include "Makefile.common"
PKGREVISION=		5

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
