# $NetBSD: Makefile,v 1.9 2012/10/03 18:28:20 asau Exp $
#

DISTNAME=		font-bh-ttf-1.0.3
PKGREVISION=		1
CATEGORIES=		fonts
MASTER_SITES=		${MASTER_SITE_XORG:=font/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://xorg.freedesktop.org/
COMMENT=		Standard Bigelow & Holmes TrueType fonts

GNU_CONFIGURE=		yes

FONTS_DIRS.ttf=		share/fonts/X11/TTF
FONTS_DIRS.x11=		share/fonts/X11/TTF

INSTALLATION_DIRS=	share/doc/font-bh-ttf

PKG_SYSCONFSUBDIR=	fontconfig
CONF_FILES=	${PREFIX}/share/fontconfig/conf.avail/42-luxi-mono.conf \
		${PKG_SYSCONFDIR}/conf.d/42-luxi-mono.conf

post-install:
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DESTDIR}${PREFIX}/share/doc/font-bh-ttf

.include "../../mk/bsd.pkg.mk"
