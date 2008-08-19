# $NetBSD: Makefile,v 1.6 2008/08/19 09:52:01 bjs Exp $
#

DISTNAME=		terminus-font-4.26
CATEGORIES=		fonts
MASTER_SITES=		http://www.is-vn.bg/hamster/

MAINTAINER=		j+pkgsrc@salmi.ch
HOMEPAGE=		http://www.is-vn.bg/hamster/jimmy-en.html
COMMENT=		Clean fixed width font

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		perl bdftopcf gzip

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--x11dir=${PREFIX}/lib/X11/fonts/misc

BUILD_TARGET=		pcf
INSTALL_TARGET=		install-pcf

FONTS_DIRS.x11=		${PREFIX}/lib/X11/fonts/misc
REQD_DIRS+=		${PREFIX}/lib/X11/fonts/misc

.include "../../mk/bsd.pkg.mk"
