# $NetBSD: Makefile,v 1.4 2012/10/03 18:28:22 asau Exp $
#

DISTNAME=		font-xfree86-type1-1.0.4
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		XFree86 cursor Type1 fonts

GNU_CONFIGURE=		yes

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

FONTS_DIRS.type1=	share/fonts/X11/Type1
FONTS_DIRS.x11=		share/fonts/X11/Type1

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
