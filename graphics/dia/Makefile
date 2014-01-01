# $NetBSD: Makefile,v 1.86 2014/01/01 11:52:19 wiz Exp $
#

.include "Makefile.common"

PKGREVISION=	19

.include "options.mk"

# just to convert the manpage
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
