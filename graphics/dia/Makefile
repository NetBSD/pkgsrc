# $NetBSD: Makefile,v 1.85 2013/10/10 14:42:12 ryoon Exp $
#

.include "Makefile.common"

PKGREVISION=	18

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
