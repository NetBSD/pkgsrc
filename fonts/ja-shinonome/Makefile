# $NetBSD: Makefile,v 1.29 2015/07/04 16:18:31 joerg Exp $
#

DISTNAME=		shinonome-0.9.11-src
PKGNAME=		ja-shinonome-0.9.11
PKGREVISION=		5
CATEGORIES=		fonts x11 japanese
MASTER_SITES=		http://openlab.ring.gr.jp/efont/dist/shinonome/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://openlab.ring.gr.jp/efont/shinonome/
COMMENT=		12, 14, 16 dots bitmap fonts for Japanese, iso8859-1
LICENSE=		public-domain

GNU_CONFIGURE=		YES
USE_TOOLS+=		gawk gmake mkfontdir perl gzip
FONTS_DIRS.x11+=	${PREFIX}/share/fonts/X11/local
FONTDIR=		${PREFIX}/share/fonts/X11/local
FOUNDRY=		Misc
ALIAS_SHINONOME=	${PREFIX}/share/examples/fonts.alias.shinonome

FILES_SUBST+=		FONTDIR=${FONTDIR:Q}
FILES_SUBST+=		ALIAS_SHINONOME=${ALIAS_SHINONOME:Q}

CONFIGURE_ARGS+=	--with-fontdir=${FONTDIR:Q}
CONFIGURE_ARGS+=	--disable-progressbar
CONFIGURE_ARGS+=	--with-foundry=${FOUNDRY:Q}

INSTALL_MAKE_FLAGS+=	FONTDIR=${DESTDIR:Q}${FONTDIR:Q}

INSTALLATION_DIRS=	share/fonts/X11/local share/examples

post-install:
	${INSTALL_DATA} ${WRKSRC}/fonts.alias ${DESTDIR}${ALIAS_SHINONOME}

.include "../../mk/bsd.pkg.mk"
