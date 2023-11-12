# $NetBSD: Makefile,v 1.124 2023/11/12 13:21:53 wiz Exp $

PKGREVISION=	32
.include "Makefile.common"

.include "options.mk"

# just to convert the manpage
TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
