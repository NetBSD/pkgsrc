# $NetBSD: Makefile,v 1.20 2023/10/21 17:10:24 gdt Exp $

.include "../../graphics/djvulibre-lib/Makefile.common"
PKGNAME=		${DISTNAME:S/-/-tools-/}
PKGREVISION=		3

MAINTAINER=		pkgsrc-users@NetBSD.org

BUILD_DIRS=		tools xmltools
INSTALL_DIRS=		tools xmltools

USE_TOOLS+=		bash:run
REPLACE_BASH+=		tools/any2djvu

.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
