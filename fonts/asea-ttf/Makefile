# $NetBSD: Makefile,v 1.2 2023/12/23 08:47:31 zafer Exp $

DISTNAME=	Asea
PKGNAME=	asea-ttf-4.13
CATEGORIES=	fonts
MASTER_SITES=	#
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://users.teilar.gr/~g1951d/
COMMENT=	Typeface for greek typography
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
