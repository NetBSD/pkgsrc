# $NetBSD: Makefile,v 1.126 2024/04/07 07:34:09 wiz Exp $

PKGREVISION=	34
.include "Makefile.common"

.include "options.mk"

# just to convert the manpage
TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
