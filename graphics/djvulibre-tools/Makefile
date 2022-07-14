# $NetBSD: Makefile,v 1.18 2022/07/14 23:46:20 dholland Exp $

.include "../../graphics/djvulibre-lib/Makefile.common"
PKGNAME=		${DISTNAME:S/-/-tools-/}
PKGREVISION=		1

MAINTAINER=		pkgsrc-users@NetBSD.org

BUILD_DIRS=		tools xmltools
INSTALL_DIRS=		tools xmltools

USE_TOOLS+=		bash:run
REPLACE_BASH+=		tools/any2djvu

.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
