# $NetBSD: Makefile,v 1.3 2007/02/19 07:57:26 joerg Exp $
#

DISTNAME=		font-ibm-type1-1.0.0
CATEGORIES=		fonts
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/font/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		IBM Courier Type1 fonts

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		FCCACHE=${TOOLS_CMD.true:Q}

FONTS_DIRS.type1=	lib/X11/fonts/Type1
FONTS_DIRS.x11=		lib/X11/fonts/Type1

.include "../../mk/bsd.pkg.mk"
