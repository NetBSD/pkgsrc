# $NetBSD: Makefile,v 1.16 2014/11/15 22:15:30 ryoon Exp $

RICTYVER=	3.2.3
DISTNAME=	Ricty-${RICTYVER}
PKGNAME=	ricty-ttf-${RICTYVER}
CATEGORIES=	fonts japanese
MASTER_SITES=	-https://github.com/yascentur/Ricty/archive/${RICTYVER}.zip
EXTRACT_SUFX=	.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://save.sys.t.u-tokyo.ac.jp/~yusa/fonts/ricty.html
COMMENT=	Migu 1M and Inconsolata based TrueType fonts for programming
LICENSE=	ipafont AND ofl-v1.1 AND public-domain

BUILD_DEPENDS+=		fontforge-[0-9]*:../../fonts/fontforge
BUILD_DEPENDS+=		migu-ttf-[0-9]*:../../fonts/migu-ttf
BUILD_DEPENDS+=		inconsolata-ttf-[0-9]*:../../fonts/inconsolata-ttf

USE_TOOLS+=		bash

# LICESE of generated TTF fonts is "ipafont AND open-font-license",
# but OPEN FONT LICENSE version 1.1 section 5) require to distribute entirely
# under the license.
RESTRICTED=		Redistribution not permitted per open-font-license PERMISSION & CONDITIONS point 5
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

USE_X11BASE=	YES
NO_CONFIGURE=	YES

INSTALLATION_DIRS=	share/fonts/X11/TTF

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
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
	${BASH} ./ricty_generator.sh \
	${INCONSOLATADIR}/share/fonts/X11/TTF/Inconsolata.otf \
	${MIGUDIR}/share/fonts/X11/TTF/migu-1m-regular.ttf \
	${MIGUDIR}/share/fonts/X11/TTF/migu-1m-bold.ttf

post-build:
	set -e; \
	cd ${WRKSRC}; \
	./misc/os2version_reviser.sh Ricty*.ttf

do-install:
.for f in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${FONTDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
