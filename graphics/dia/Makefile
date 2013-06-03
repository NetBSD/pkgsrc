# $NetBSD: Makefile,v 1.79 2013/06/03 10:05:09 wiz Exp $
#

.include "Makefile.common"

PKGREVISION=	12

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
