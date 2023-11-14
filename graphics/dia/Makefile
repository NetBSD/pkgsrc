# $NetBSD: Makefile,v 1.125 2023/11/14 14:02:00 wiz Exp $

PKGREVISION=	33
.include "Makefile.common"

.include "options.mk"

# just to convert the manpage
TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
