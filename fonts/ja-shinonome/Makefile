# $NetBSD: Makefile,v 1.38 2022/06/28 11:33:53 wiz Exp $
#

DISTNAME=		shinonome-0.9.11p1
PKGNAME=		ja-${DISTNAME:S/p/pl/}
PKGREVISION=		5
CATEGORIES=		fonts x11 japanese
MASTER_SITES=		http://openlab.ring.gr.jp/efont/dist/shinonome/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://openlab.ring.gr.jp/efont/shinonome/
COMMENT=		12, 14, 16 dots bitmap fonts for Japanese, iso8859-1
LICENSE=		public-domain

WRKSRC=			${WRKDIR}/shinonome-0.9.11

GNU_CONFIGURE=		YES
USE_TOOLS+=		bdftopcf gmake mkfontdir perl gzip
FONTDIR=		${PREFIX}/share/fonts/X11/local
FONTS_DIRS.x11+=	${FONTDIR}
ALIAS_SHINONOME=	${PREFIX}/share/examples/fonts.alias.shinonome

FILES_SUBST+=		FONTDIR=${FONTDIR:Q}
FILES_SUBST+=		ALIAS_SHINONOME=${ALIAS_SHINONOME:Q}

CONFIGURE_ARGS+=	--with-fontdir=${FONTDIR:Q}
CONFIGURE_ARGS+=	--enable-compress=gzip

INSTALL_MAKE_FLAGS+=	FONTDIR=${DESTDIR:Q}${FONTDIR:Q}

INSTALLATION_DIRS=	share/fonts/X11/local share/examples

post-install:
	${INSTALL_DATA} ${WRKSRC}/fonts.alias ${DESTDIR}${ALIAS_SHINONOME}

.include "../../mk/bsd.pkg.mk"
