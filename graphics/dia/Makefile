# $NetBSD: Makefile,v 1.90 2015/04/25 14:23:08 tnn Exp $
#

.include "Makefile.common"

PKGREVISION=	23

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
