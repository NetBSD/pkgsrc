# $NetBSD: Makefile,v 1.3 2006/09/07 17:19:41 obache Exp $
#

DISTNAME=		terminus-font-4.20
CATEGORIES=		fonts
MASTER_SITES=		http://www.is-vn.bg/hamster/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.is-vn.bg/hamster/jimmy-en.html
COMMENT=		Clean fixed width font

USE_TOOLS+=		perl bdftopcf gzip

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--x11dir=${PREFIX}/lib/X11/fonts/misc

BUILD_TARGET=		pcf
INSTALL_TARGET=		install-pcf

FONTS_DIRS.x11=		${PREFIX}/lib/X11/fonts/misc
REQD_DIRS+=		${PREFIX}/lib/X11/fonts/misc

.include "../../mk/bsd.pkg.mk"
