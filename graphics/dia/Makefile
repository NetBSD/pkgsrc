# $NetBSD: Makefile,v 1.76 2013/01/26 21:37:43 adam Exp $
#

.include "Makefile.common"

PKGREVISION=	9

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
