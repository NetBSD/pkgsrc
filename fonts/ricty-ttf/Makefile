# $NetBSD: Makefile,v 1.1.1.1 2011/05/08 11:05:31 ryoon Exp $
#

DISTNAME=	Ricty-2.0.1
PKGNAME=	${DISTNAME:tl:S/-/-ttf-/}
CATEGORIES=	fonts japanese
MASTER_SITES=	http://save.sys.t.u-tokyo.ac.jp/~yusa/fonts/ricty/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://save.sys.t.u-tokyo.ac.jp/~yusa/fonts/ricty.html
COMMENT=	Migu 1M and Inconsolata based TrueType fonts for programming
LICENSE=	ipafont AND open-font-license AND mplusfont

PKG_DESTDIR_SUPPORT=	user-destdir

USE_X11BASE=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	lib/X11/fonts/TTF \
			${DOCSDIR}

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALL_FONTS=	Ricty-Bold.ttf \
		Ricty-Regular.ttf
INSTALL_DOCS=	README \
		Licenses/IPA_Font_License_Agreement_v1.0.txt \
		Licenses/LICENSE_J \
		Licenses/OFL.txt

USE_LANGUAGES=	# none

do-install:
.for f in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${FONTDIR}
.endfor
.for f in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
