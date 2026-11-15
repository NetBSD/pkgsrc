# $NetBSD: Makefile,v 1.20 2026/11/15 13:14:45 vins Exp $

DISTNAME=	xwpe-1.6.9
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_CODEBERG:=mendezr/xwpe/releases/download/v${PKGVERSION_NOREV}/}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://www.identicalsoftware.com/xwpe/
COMMENT=	Programming environment for UNIX systems
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	makeinfo gmake pkg-config

USE_CURSES=	getmouse resizeterm wide
FAKE_NCURSES=	yes

GNU_CONFIGURE=	yes
INFO_FILES=	yes

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Replacing hard-coded paths.
SUBST_FILES.paths=	unixkeys.h we_fl_unix.c
SUBST_VARS.paths=	PREFIX PKGMANDIR PKGINFODIR

CONFIGURE_ARGS+=	--without-wayland
CONFIGURE_ARGS+=	--without-gpm

.include "options.mk"

INSTALLATION_DIRS+=	share/pixmaps

post-install:
	${INSTALL_DATA} ${FILESDIR}/xwpe.desktop	\
		${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${FILESDIR}/xwpe.xpm		\
		${DESTDIR}${PREFIX}/share/pixmaps

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../devel/libvterm03/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
