# $NetBSD: Makefile,v 1.27 2019/11/05 08:59:12 pho Exp $

DISTNAME=	# empty
PKGNAME=	ricty-ttf-4.1.1
CATEGORIES=	fonts japanese

# The official distribution of Ricty is unfortunately not versioned.
DIST_SUBDIR=	${PKGBASE}
DISTFILES=	ricty_generator.sh os2version_reviser.sh
MASTER_SITES=	http://www.yusa.lab.uec.ac.jp/~yusa/ricty/
EXTRACT_CMD=	${CP} -f "$$extract_file" "${WRKSRC}"
WRKSRC=		${WRKDIR}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.yusa.lab.uec.ac.jp/~yusa/ricty.html
COMMENT=	Migu 1M and Inconsolata based TrueType fonts for programming
LICENSE=	ipafont AND ofl-v1.1 AND 2-clause-bsd

USE_TOOLS+=		bash
BUILD_DEPENDS+=		fontforge-[0-9]*:../../fonts/fontforge
BUILD_DEPENDS+=		migu-ttf>=20150712:../../fonts/migu-ttf
BUILD_DEPENDS+=		inconsolata-ttf>=2.000:../../fonts/inconsolata-ttf

# LICESE of generated TTF fonts is "ipafont AND open-font-license",
# but OPEN FONT LICENSE version 1.1 section 5) require to distribute entirely
# under the license.
RESTRICTED=		Redistribution not permitted per open-font-license PERMISSION & CONDITIONS point 5
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

USE_LANGUAGES=	# none

NO_CONFIGURE=	YES

# We can't use ../../mk/fonts.mk because it defines NO_BUILD.
TTF_FONTS_DIR=		${PREFIX}/share/fonts/X11/TTF
INSTALLATION_DIRS=	${TTF_FONTS_DIR}

do-build:
	set -e; \
	cd ${WRKSRC}; \
	${PKGSRC_SETENV} ${MAKE_ENV} \
		${BASH} -x ./ricty_generator.sh \
		${TTF_FONTS_DIR}/Inconsolata-Regular.ttf \
		${TTF_FONTS_DIR}/Inconsolata-Bold.ttf \
		${TTF_FONTS_DIR}/migu-1m-regular.ttf \
		${TTF_FONTS_DIR}/migu-1m-bold.ttf

post-build:
	set -e; \
	cd ${WRKSRC}; \
	${BASH} -x ./os2version_reviser.sh Ricty*.ttf

do-install:
	@${STEP_MSG} "Installing all .ttf files from ${WRKSRC}"
	${FIND} ${WRKSRC} -name ${DESTDIR:T} -prune -o -iname '*.ttf' -exec \
		${INSTALL_DATA} "{}" ${DESTDIR}${TTF_FONTS_DIR} ";"

.include "../../mk/bsd.pkg.mk"
