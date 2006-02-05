# $NetBSD: Makefile,v 1.15 2006/02/05 23:09:10 joerg Exp $
#

DISTNAME=		shinonome-0.9.10-src
PKGNAME=		ja-shinonome-0.9.10
PKGREVISION=		1
CATEGORIES=		fonts x11 japanese
MASTER_SITES=		http://openlab.ring.gr.jp/efont/dist/shinonome/ \
			http://openlab.ring.gr.jp/efont/dist/shinonome/old/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://openlab.ring.gr.jp/efont/shinonome/
COMMENT=		12, 14, 16 dots bitmap fonts for Japanese, iso8859-1

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_TOOLS+=		gawk gmake mkfontdir perl
FONTDIR=		${PREFIX}/lib/X11/fonts/local
FOUNDRY=		Misc
ALIAS_SHINONOME=	${PREFIX}/share/examples/fonts.alias.shinonome

DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

FILES_SUBST+=		FONTDIR=${FONTDIR:Q}
FILES_SUBST+=		ALIAS_SHINONOME=${ALIAS_SHINONOME:Q}

CONFIGURE_ARGS+=	--with-fontdir=${FONTDIR:Q}
CONFIGURE_ARGS+=	--disable-progressbar
CONFIGURE_ARGS+=	--with-foundry=${FOUNDRY:Q}

.include "../../mk/x11.buildlink3.mk"

do-install:
	cd ${WRKSRC}; \
	${MAKE_PROGRAM} install; \
	${INSTALL_DATA} ${WRKSRC}/fonts.alias ${ALIAS_SHINONOME}

.include "../../mk/bsd.pkg.mk"
