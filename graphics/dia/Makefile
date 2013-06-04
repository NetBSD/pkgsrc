# $NetBSD: Makefile,v 1.80 2013/06/04 22:16:15 tron Exp $
#

.include "Makefile.common"

PKGREVISION=	13

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
