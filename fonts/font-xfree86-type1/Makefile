# $NetBSD: Makefile,v 1.6 2023/02/28 07:20:30 wiz Exp $

DISTNAME=		font-xfree86-type1-1.0.5
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		XFree86 cursor Type1 fonts

GNU_CONFIGURE=		yes

INSTALLATION_DIRS+=	share/doc/${PKGBASE}

FONTS_DIRS.type1=	share/fonts/X11/Type1
FONTS_DIRS.x11=		share/fonts/X11/Type1

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
