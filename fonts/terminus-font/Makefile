# $NetBSD: Makefile,v 1.9 2012/10/03 18:28:31 asau Exp $
#

DISTNAME=		terminus-font-4.36
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=terminus-font/}

MAINTAINER=		j+pkgsrc@salmi.ch
HOMEPAGE=		http://terminus-font.sourceforge.net/
COMMENT=		Clean, fixed-width font
LICENSE=		open-font-license

USE_TOOLS+=		bdftopcf gmake gzip perl

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--x11dir=${PREFIX}/lib/X11/fonts/misc

BUILD_TARGET=		pcf
INSTALL_TARGET=		install-pcf

FONTS_DIRS.x11=		${PREFIX}/lib/X11/fonts/misc
REQD_DIRS+=		${PREFIX}/lib/X11/fonts/misc

.include "../../mk/bsd.pkg.mk"
