# $NetBSD: Makefile,v 1.78 2013/02/16 11:21:43 wiz Exp $
#

.include "Makefile.common"

PKGREVISION=	11

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
