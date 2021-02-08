# $NetBSD: Makefile,v 1.4 2021/02/08 07:57:03 fcambus Exp $

DISTNAME=	le-1.16.8
CATEGORIES=	editors
MASTER_SITES=	http://lav.yar.ru/download/le/

MAINTAINER=	fcambus@NetBSD.org
HOMEPAGE=	http://lav.yar.ru/programs.html
COMMENT=	Full screen text editor inspired by Norton Editor
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
