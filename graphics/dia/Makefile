# $NetBSD: Makefile,v 1.72 2012/09/07 19:16:43 adam Exp $
#

.include "Makefile.common"

PKGREVISION=	5

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
