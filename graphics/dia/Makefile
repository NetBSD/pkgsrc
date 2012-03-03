# $NetBSD: Makefile,v 1.70 2012/03/03 00:13:11 wiz Exp $
#

.include "Makefile.common"

PKGREVISION=	3

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
