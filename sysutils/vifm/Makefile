# $NetBSD: Makefile,v 1.31 2019/06/10 17:33:29 nia Exp $
#

DISTNAME=	vifm-0.10
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
REPLACE_PERL=	src/vifm-convert-dircolors

REPLACE_BASH+=	data/vifm-media

# using libmagic for file identification, don't use gtk
CONFIGURE_ARGS+=	--with-libmagic
CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--without-X11
CONFIGURE_ARGS+=	--without-dyn-X11

.include "../../sysutils/file/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
