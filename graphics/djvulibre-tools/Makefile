# $NetBSD: Makefile,v 1.23 2025/07/04 06:25:30 wiz Exp $

.include "../../graphics/djvulibre-lib/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-tools-/}

MAINTAINER=	pkgsrc-users@NetBSD.org

BUILD_DIRS=	tools xmltools
INSTALL_DIRS=	tools xmltools

USE_TOOLS+=	bash:run
REPLACE_BASH+=	tools/any2djvu

.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
