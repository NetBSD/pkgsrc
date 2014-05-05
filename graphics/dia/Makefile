# $NetBSD: Makefile,v 1.88 2014/05/05 00:47:55 ryoon Exp $
#

.include "Makefile.common"

PKGREVISION=	21

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
