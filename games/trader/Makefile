# $NetBSD: Makefile,v 1.2 2022/06/27 15:29:15 fcambus Exp $

DISTNAME=	trader-7.16
CATEGORIES=	games
MASTER_SITES=	https://ftp.zap.org.au/pub/trader/unix/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.zap.org.au/projects/trader/
COMMENT=	Simple text-based game of interstellar trading
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
