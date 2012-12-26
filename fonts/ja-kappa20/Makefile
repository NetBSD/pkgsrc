# $NetBSD: Makefile,v 1.16 2012/12/26 21:14:06 ryoon Exp $

DISTNAME=		Kappa20-0.394
PKGNAME=		ja-kappa20-0.394
PKGREVISION=		1
CATEGORIES=		fonts x11 japanese
MASTER_SITES=		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://kappa.allnet.ne.jp/20dot.fonts/
COMMENT=		20x20 dots X11 bitmap font for Japanese with several extra fonts

USE_X11BASE=		YES
FONTDIR=		${PREFIX}/lib/X11/fonts/local
ALIAS_KAPPA=		${PREFIX}/share/examples/fonts.alias.Kappa20

USE_TOOLS+=		bdftopcf gzip mkfontdir patch

FILES_SUBST+=		FONTDIR=${FONTDIR:Q}
FILES_SUBST+=		ALIAS_KAPPA=${ALIAS_KAPPA:Q}

# do not build experimental JIS X 0213 font.
BUILD_TARGET=		default

INSTALLATION_DIRS=	lib/X11/fonts/local share/doc share/examples

do-install:
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/README.Kappa20
	${INSTALL_DATA} ${WRKSRC}/pcf/fonts.alias ${DESTDIR}${ALIAS_KAPPA}
	${INSTALL_DATA} ${WRKSRC}/pcf/*.pcf.* ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
