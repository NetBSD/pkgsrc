# $NetBSD: Makefile,v 1.1.1.1 2011/02/27 19:00:50 ryoon Exp $
#

DISTNAME=	motoya-al-fonts-20100921
PKGNAME=	${DISTNAME:S/-al//}
CATEGORIES=	fonts japanese
MASTER_SITES=	${MASTER_SITE_FREEBSD_LOCAL:=hrs/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://android.git.kernel.org/?p=platform/frameworks/base.git;a=tree;f=data/fonts
COMMENT=	Motoya L Cider W3 and L Mulberry W3 fonts
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
USE_X11BASE=	YES
NO_BUILD=	YES

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	lib/X11/fonts/TTF \
			${DOCDIR}

INSTALL_FONTS=	MTLc3m.ttf \
		MTLmr3m.ttf

INSTALL_DOCS=	NOTICE \
		newsrelease20100921.pdf

do-install:
.for f in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${FONTDIR}
.endfor
.for f in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
