# $NetBSD: Makefile,v 1.4 2011/05/28 11:15:24 ryoon Exp $
#

DISTNAME=	Ricty-3.0.1
PKGNAME=	${DISTNAME:tl:S/-/-ttf-/}
CATEGORIES=	fonts japanese
MASTER_SITES=	http://save.sys.t.u-tokyo.ac.jp/~yusa/fonts/ricty/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://save.sys.t.u-tokyo.ac.jp/~yusa/fonts/ricty.html
COMMENT=	Migu 1M and Inconsolata based TrueType fonts for programming
LICENSE=	ipafont AND open-font-license AND mplusfont AND public-domain

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=		fontforge-[0-9]*:../../fonts/fontforge
BUILD_DEPENDS+=		migu-ttf-[0-9]*:../../fonts/migu-ttf
BUILD_DEPENDS+=		inconsolata-ttf-[0-9]*:../../fonts/inconsolata-ttf

NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

USE_X11BASE=	YES
NO_CONFIGURE=	YES

INSTALLATION_DIRS=	lib/X11/fonts/TTF

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALL_FONTS=	Ricty-Bold.ttf \
		Ricty-Regular.ttf \
		RictyDiscord-Bold.ttf \
		RictyDiscord-Regular.ttf

USE_LANGUAGES=	# none

FIND_PREFIX:=	INCONSOLATADIR=inconsolata-ttf
FIND_PREFIX+=	MIGUDIR=migu-ttf
.include "../../mk/find-prefix.mk"

do-build:
	set -e; \
	cd ${WRKSRC}; \
	./ricty_generator.sh \
	${INCONSOLATADIR}/lib/X11/fonts/TTF/Inconsolata.otf \
	${MIGUDIR}/lib/X11/fonts/TTF/Migu-1M-regular.ttf \
	${MIGUDIR}/lib/X11/fonts/TTF/Migu-1M-bold.ttf

do-install:
.for f in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${FONTDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
