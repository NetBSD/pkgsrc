# $NetBSD: Makefile,v 1.41 2026/01/01 19:41:35 wiz Exp $

DISTNAME=	vifm-0.14.3
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vifm/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://vifm.info/
COMMENT=	Curses based file manager with vi like keybindings
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	bash gmake nroff perl pkg-config

USE_CURSES=	resize_term wide
FAKE_NCURSES=	yes

SUBST_CLASSES+=		curses
SUBST_SED.curses+=	-e 's,max_colors,vifm_max_colors,g'
SUBST_FILES.curses+=	src/ui/color_manager.h
SUBST_FILES.curses+=	src/ui/escape.c
SUBST_FILES.curses+=	src/ui/escape.h
SUBST_FILES.curses+=	src/ui/ui.c
SUBST_FILES.curses+=	tests/colmgr/suite.c
SUBST_FILES.curses+=	tests/test-support/test-utils.c
SUBST_MESSAGE.curses=	Improve curses compatibility
SUBST_STAGE.curses=	pre-build

# Unbundling lua, see patches/
LIBS+=		-llua5.4

# reallocarray
CFLAGS.NetBSD+=	-D_OPENBSD_SOURCE

REPLACE_PERL+=		src/vifm-convert-dircolors

REPLACE_BASH+=		data/vifm-media
REPLACE_PYTHON+=	data/vifm-media-osx

# using libmagic for file identification, don't use gtk
CONFIGURE_ARGS+=	--with-libmagic
CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--without-X11
CONFIGURE_ARGS+=	--without-dyn-X11

PLIST_VARS+=		notdarwin
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin"
PLIST.notdarwin=	yes
PYTHON_FOR_BUILD_ONLY=	tool
.endif

.include "../../lang/lua54/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
# not included to avoid X11 dependency
#.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
