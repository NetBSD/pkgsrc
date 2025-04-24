# $NetBSD: Makefile,v 1.22 2025/04/24 14:14:15 wiz Exp $

PKGREVISION= 1
.include "../../graphics/djvulibre-lib/Makefile.common"

PKGNAME=	${DISTNAME:S/-/-tools-/}

MAINTAINER=	pkgsrc-users@NetBSD.org

BUILD_DIRS=	tools xmltools
INSTALL_DIRS=	tools xmltools

USE_TOOLS+=	bash:run
REPLACE_BASH+=	tools/any2djvu

.include "../../graphics/djvulibre-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
