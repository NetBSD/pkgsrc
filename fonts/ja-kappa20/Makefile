# $NetBSD: Makefile,v 1.18 2015/07/04 16:18:31 joerg Exp $

DISTNAME=		Kappa20-0.394
PKGNAME=		ja-kappa20-0.394
PKGREVISION=		2
CATEGORIES=		fonts x11 japanese
MASTER_SITES=		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg-ja@jp.NetBSD.org
HOMEPAGE=		http://kappa.allnet.ne.jp/20dot.fonts/
COMMENT=		20x20 dots X11 bitmap font for Japanese with several extra fonts

FONTDIR=		${PREFIX}/share/fonts/X11/local
ALIAS_KAPPA=		${PREFIX}/share/examples/fonts.alias.Kappa20

USE_TOOLS+=		bdftopcf gzip mkfontdir patch

FILES_SUBST+=		FONTDIR=${FONTDIR:Q}
FILES_SUBST+=		ALIAS_KAPPA=${ALIAS_KAPPA:Q}

# do not build experimental JIS X 0213 font.
BUILD_TARGET=		default

INSTALLATION_DIRS=	share/fonts/X11/local share/doc share/examples

do-install:
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${PREFIX}/share/doc/README.Kappa20
	${INSTALL_DATA} ${WRKSRC}/pcf/fonts.alias ${DESTDIR}${ALIAS_KAPPA}
	${INSTALL_DATA} ${WRKSRC}/pcf/*.pcf.* ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
