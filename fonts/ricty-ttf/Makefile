# $NetBSD: Makefile,v 1.11 2012/10/03 18:28:30 asau Exp $
#

DISTNAME=	yascentur-Ricty-3.2.0-0-gb9d8b9c.tar.gz
PKGNAME=	ricty-ttf-3.2.0
CATEGORIES=	fonts japanese
MASTER_SITES=	-https://github.com/yascentur/Ricty/tarball/3.2.0

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://save.sys.t.u-tokyo.ac.jp/~yusa/fonts/ricty.html
COMMENT=	Migu 1M and Inconsolata based TrueType fonts for programming
LICENSE=	ipafont AND open-font-license AND mplusfont AND public-domain

# Force using "curl" for fetching the distribution file. It is only available
# over HTTPS and "curl" is the only fetch program which always supports HTTPS.
FETCH_USING=	curl

BUILD_DEPENDS+=		fontforge-[0-9]*:../../fonts/fontforge
BUILD_DEPENDS+=		migu-ttf-20111002:../../fonts/migu-ttf
BUILD_DEPENDS+=		inconsolata-ttf-[0-9]*:../../fonts/inconsolata-ttf

# LICESE of generated TTF fonts is "ipafont AND open-font-license",
# but OPEN FONT LICENSE version 1.1 section 5) require to distribute entirely
# under the license.
RESTRICTED=		Redistribution not permitted per open-font-license PERMISSION & CONDITIONS point 5
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

USE_X11BASE=	YES
NO_CONFIGURE=	YES

WRKSRC=		${WRKDIR}/yascentur-Ricty-b9d8b9c

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
	${MIGUDIR}/lib/X11/fonts/TTF/migu-1m-regular.ttf \
	${MIGUDIR}/lib/X11/fonts/TTF/migu-1m-bold.ttf

post-build:
	set -e; \
	cd ${WRKSRC}; \
	./misc/os2version_reviser.sh Ricty*.ttf

do-install:
.for f in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${FONTDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
