# $NetBSD: Makefile,v 1.1.1.1 2003/03/15 20:40:56 kei Exp $

DISTNAME=		Kappa20-0.394
PKGNAME=		ja-kappa20-0.394
CATEGORIES=		fonts x11 japanese
MASTER_SITES=		${MASTER_SITE_LOCAL}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg-ja@jp.netbsd.org
HOMEPAGE=		http://kappa.allnet.ne.jp/20dot.fonts/
COMMENT=		20x20 dots X11 bitmap font for Japanese with several extra fonts

USE_X11BASE=		YES
FONTDIR=		${PREFIX}/lib/X11/fonts/local
ALIAS_KAPPA=		${PREFIX}/share/examples/fonts.alias.Kappa20

FILES_SUBST+=		FONTDIR=${FONTDIR}
FILES_SUBST+=		ALIAS_KAPPA=${ALIAS_KAPPA}

# do not build experimental JIS X 0213 font.
ALL_TARGET=		default

do-install:
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/README.Kappa20; \
	${INSTALL_DATA} ${WRKSRC}/pcf/fonts.alias ${ALIAS_KAPPA}; \
	${INSTALL_DATA} ${WRKSRC}/pcf/*.pcf.* ${FONTDIR}

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
