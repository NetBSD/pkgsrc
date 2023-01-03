# $NetBSD: Makefile,v 1.19 2023/01/03 17:37:18 wiz Exp $

.include "../../graphics/djvulibre-lib/Makefile.common"
PKGNAME=		${DISTNAME:S/-/-tools-/}
PKGREVISION=		2

MAINTAINER=		pkgsrc-users@NetBSD.org

BUILD_DIRS=		tools xmltools
INSTALL_DIRS=		tools xmltools

USE_TOOLS+=		bash:run
REPLACE_BASH+=		tools/any2djvu

.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
