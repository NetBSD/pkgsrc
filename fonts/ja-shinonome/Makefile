# $NetBSD: Makefile,v 1.1.1.1 2003/03/15 20:57:50 kei Exp $

DISTNAME=		shinonome-0.9.9-src
PKGNAME=		ja-shinonome-0.9.9
CATEGORIES=		fonts x11 japanese
MASTER_SITES=		http://openlab.ring.gr.jp/efont/dist/shinonome/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg-ja@jp.netbsd.org
HOMEPAGE=		http://openlab.ring.gr.jp/efont/shinonome/
COMMENT=		12, 14, 16 dots bitmap fonts for Japanese, iso8859-1

GNU_CONFIGURE=		YES
USE_PERL5=		build
USE_X11BASE=		YES
USE_GMAKE=		YES
FONTDIR=		${PREFIX}/lib/X11/fonts/local
FOUNDRY=		Misc
ALIAS_SHINONOME=	${PREFIX}/share/examples/fonts.alias.shinonome

FILES_SUBST+=		FONTDIR=${FONTDIR}
FILES_SUBST+=		ALIAS_SHINONOME=${ALIAS_SHINONOME}

CONFIGURE_ARGS+=	--with-fontdir=${FONTDIR}
CONFIGURE_ARGS+=	--disable-progressbar
CONFIGURE_ARGS+=	--with-foundry=${FOUNDRY}

do-install:
	cd ${WRKSRC}; \
	${MAKE_PROGRAM} install; \
	${INSTALL_DATA} ${WRKSRC}/fonts.alias ${ALIAS_SHINONOME}

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
