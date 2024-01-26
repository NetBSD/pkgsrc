# $NetBSD: mbrolavox.mk,v 1.1 2024/01/26 12:58:05 wiz Exp $
#
# shared Makefile fragment for mbrola voices
# set VOX before including this (e.g. to 'en1')

COMMITS=	16
DISTNAME=	MBROLA-voices-0.0.0.${COMMITS}
PKGNAME=	mbrolavox-${VOX}-0.0.0.${COMMITS}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=numediart/}
GITHUB_PROJECT=	MBROLA-voices
GITHUB_TAG=	fe05a0ccef6a941207fd6aaad0b31294a1f93a51

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/numediart/MBROLA-voices
# the particular license of this voice is included in ${DESTDIR}${MHOME}${VOX}
LICENSE=		mbrola-voices-license

RESTRICTED=		Commercial distribution not allowed without permission from the authors
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}

DEPENDS=	mbrola-[0-9]*:../../audio/mbrola

USE_TOOLS+=	pax

NO_BUILD=	yes

MHOME=	${PREFIX}/share/mbrola/voices

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${MHOME}
	cd ${WRKSRC}/data && pax -pp -rw ${VOX} ${DESTDIR}${MHOME}
