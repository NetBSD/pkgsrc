# $NetBSD: Makefile,v 1.8 2022/06/28 11:33:46 wiz Exp $

DISTNAME=	le-1.16.8
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	http://lav.yar.ru/download/le/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lav.yar.ru/programs.html
COMMENT=	Full screen text editor inspired by Norton Editor
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	perl

CONFIGURE_ARGS+=	--with-curses-include=${BUILDLINK_PREFIX.curses}/include
CONFIGURE_ARGS+=	--with-curses-lib=${BUILDLINK_PREFIX.curses}/lib

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
