# $NetBSD: Makefile,v 1.39 2022/06/28 11:36:06 wiz Exp $
#

DISTNAME=	vifm-0.12
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=vifm/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://vifm.info/
COMMENT=	Curses based file manager with vi like keybindings
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	bash gmake perl pkg-config

USE_CURSES=	resize_term wide
FAKE_NCURSES=	yes

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
.include "../../mk/bsd.pkg.mk"
