# $NetBSD: Makefile,v 1.64 2011/07/21 13:05:56 obache Exp $
#

.include "Makefile.common"
PKGREVISION=		6

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
