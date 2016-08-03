# $NetBSD: Makefile,v 1.93 2016/08/03 10:22:50 adam Exp $

PKGREVISION= 2
.include "Makefile.common"

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
