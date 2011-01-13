# $NetBSD: Makefile,v 1.62 2011/01/13 13:37:58 wiz Exp $
#

.include "Makefile.common"
PKGREVISION=		4

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
