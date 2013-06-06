# $NetBSD: Makefile,v 1.81 2013/06/06 12:54:28 wiz Exp $
#

.include "Makefile.common"

PKGREVISION=	14

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
