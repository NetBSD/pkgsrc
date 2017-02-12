# $NetBSD: Makefile,v 1.95 2017/02/12 06:25:25 ryoon Exp $

PKGREVISION= 4
.include "Makefile.common"

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
