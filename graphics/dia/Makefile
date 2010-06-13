# $NetBSD: Makefile,v 1.59 2010/06/13 22:44:28 wiz Exp $
#

.include "Makefile.common"
PKGREVISION=		1

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
