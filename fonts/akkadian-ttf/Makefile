# $NetBSD: Makefile,v 1.1.1.1 2014/08/09 16:21:27 wiz Exp $

DISTNAME=	Akkadian
PKGNAME=	akkadian-ttf-7.15
CATEGORIES=	fonts
MASTER_SITES=	http://users.teilar.gr/~g1951d/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://users.teilar.gr/~g1951d/
COMMENT=	Typeface for various Cuneiform scripts and Neo-Assyrian signs
# Fonts in this site are offered free for any use; they may be
# installed, embedded, opened, edited, modified, regenerated, posted,
# packaged and redistributed.
LICENSE=	public-domain

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}

USE_LANGUAGES=	# none
NO_CONFIGURE=	yes
NO_BUILD=	yes

FONTS_DIRS.ttf=	${PREFIX}/share/fonts/X11/TTF

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}
INSTALLATION_DIRS=	share/fonts/X11/TTF ${DOCDIR} ${FONTS_DIRS.ttf}

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DESTDIR}${FONTS_DIRS.ttf}
	${INSTALL_DATA} ${WRKSRC}/*.docx ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
