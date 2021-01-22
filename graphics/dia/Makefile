# $NetBSD: Makefile,v 1.111.2.1 2021/01/22 18:11:31 bsiegert Exp $

PKGREVISION=	21
.include "Makefile.common"

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
