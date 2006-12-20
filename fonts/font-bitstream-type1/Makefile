# $NetBSD: Makefile,v 1.2 2006/12/20 14:19:20 joerg Exp $
#

DISTNAME=		font-bitstream-type1-1.0.0
CATEGORIES=		fonts
MASTER_SITES=		http://xorg.freedesktop.org/releases/individual/font/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Bitstream Charter and Courier Type 1 outline fonts

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		FCCACHE=${TRUE:Q}

FONTS_DIRS.type1+=	lib/X11/fonts/Type1
FONTS_DIRS.x11+=	lib/X11/fonts/Type1

INSTALLATION_DIRS=	share/doc/font-bitstream-type1

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/font-bitstream-type1

.include "../../mk/bsd.pkg.mk"
