# $NetBSD: Makefile,v 1.101 2018/11/14 22:21:36 kleink Exp $

PKGREVISION= 10
.include "Makefile.common"

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
