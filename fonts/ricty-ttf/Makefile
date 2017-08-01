# $NetBSD: Makefile,v 1.23 2017/08/01 17:40:11 wiz Exp $

DISTNAME=	Ricty-3.2.4
PKGNAME=	${DISTNAME:S/Ricty/ricty-ttf/}
GITHUB_PROJECT=		Ricty
GITHUB_TAG=             ${PKGVERSION_NOREV}
CATEGORIES=	fonts japanese
MASTER_SITES=	${MASTER_SITE_GITHUB:=yascentur/}

MAINTAINER=	ryoon@NetBSD.org
#HOMEPAGE=	https://github.com/yascentur/Ricty
COMMENT=	Migu 1M and Inconsolata based TrueType fonts for programming
LICENSE=	ipafont AND ofl-v1.1 AND 2-clause-bsd

USE_TOOLS+=		bash
BUILD_DEPENDS+=		fontforge-[0-9]*:../../fonts/fontforge
BUILD_DEPENDS+=		migu-ttf-[0-9]*:../../fonts/migu-ttf
BUILD_DEPENDS+=		inconsolata-ttf-[0-9]*:../../fonts/inconsolata-ttf

# LICESE of generated TTF fonts is "ipafont AND open-font-license",
# but OPEN FONT LICENSE version 1.1 section 5) require to distribute entirely
# under the license.
RESTRICTED=		Redistribution not permitted per open-font-license PERMISSION & CONDITIONS point 5
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

NO_CONFIGURE=	YES

INSTALLATION_DIRS=	share/fonts/X11/TTF

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALL_FONTS=	Ricty-Bold.ttf \
		Ricty-Regular.ttf \
		RictyDiscord-Bold.ttf \
		RictyDiscord-Regular.ttf

USE_LANGUAGES=	# none

do-build:
	set -e; \
	cd ${WRKSRC}; \
	${PKGSRC_SETENV} ${MAKE_ENV} \
	${BASH} -x ./ricty_generator.sh \
	${LOCALBASE}/share/fonts/X11/TTF/Inconsolata.otf \
	${LOCALBASE}/share/fonts/X11/TTF/migu-1m-regular.ttf \
	${LOCALBASE}/share/fonts/X11/TTF/migu-1m-bold.ttf

post-build:
	set -e; \
	cd ${WRKSRC}; \
	./misc/os2version_reviser.sh Ricty*.ttf

do-install:
.for f in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${FONTDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
