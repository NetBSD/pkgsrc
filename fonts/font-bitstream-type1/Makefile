# $NetBSD: Makefile,v 1.1.1.1 2006/11/14 20:24:11 joerg Exp $
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
FONTS_DIRS.type1+=	lib/X11/fonts/Type1

INSTALLATION_DIRS=	share/doc/font-bitstream-type1

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/font-bitstream-type1

.include "../../mk/bsd.pkg.mk"
