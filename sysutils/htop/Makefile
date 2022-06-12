# $NetBSD: Makefile,v 1.29 2022/06/12 04:48:53 nia Exp $

DISTNAME=	htop-3.2.1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_GITHUB:=htop-dev/}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://htop.dev/
COMMENT=	Enhanced version of top utility
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoreconf automake
USE_CURSES=	getmouse

.include "../../mk/curses.buildlink3.mk"

.if ${CURSES_TYPE} != "ncursesw"
# See netbsd/README.md
CONFIGURE_ARGS+=	--disable-unicode
.endif

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./autogen.sh

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
