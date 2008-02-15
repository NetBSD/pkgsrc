# $NetBSD: Makefile,v 1.20 2008/02/15 12:25:59 obache Exp $
#

DISTNAME=		RealPlayer10GOLD
# Exact version obtained from  the output of
#   file RealPlayer10GOLD.rpm
PKGNAME=		RealPlayerGold-10.0.9.809.20070726
CATEGORIES=		multimedia
MASTER_SITES=		http://forms.real.com/real/player/download.html?f=unix/
EXTRACT_SUFX=		.rpm

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.real.com/linux/
COMMENT=		Real Audio and Video Player

RESTRICTED=		Redistribution not permitted
NO_SRC_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

PKGVER=			${PKGNAME_NOREV:S/^RealPlayerGold-//}
DIST_SUBDIR=		${PKGNAME_NOREV}

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base fontconfig freetype2 gtk2 x11

EMUL_PKG_FMT=		rpm
RPM2PKG_STRIP=		3
RPM2PKG_PREFIX=		${PREFIX}
RPM2PKG_SUBPREFIX=	lib
RPM2PKG_STAGE=		do-install
RUN_LDCONFIG=		no

REALPLAYER_HOME=	${PREFIX}/lib/RealPlayer

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-install
SUBST_FILES.paths=	${REALPLAYER_HOME}/realplay
SUBST_SED.paths=	-e 's,/bin/true,${TRUE},g'
SUBST_MESSAGE.paths=	Fixing hardcoded paths.

# Verify that the version of the distfile (which changes often without
# the name changing) is still correct.  This helps sort out download
# errors vs. out-of-date-pkgsrc errors.
#
post-fetch:
	${RUN} ver=`file ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} | ${SED} -e 's;.*Player-;;g'  -e 's;-;.;g'` ; \
		if [ "$$ver" != "${PKGVER}" ] ; then \
			${ECHO} "It appears that real.com has made a new version ($$ver) available so this" ; \
			${ECHO} "package will need updating to work correctly.  That likely the reason for" ; \
			${ECHO} "the checksum failure." ; \
		fi

do-build:
	${SED} -e 's|@REALPLAYER_HOME@|${REALPLAYER_HOME}|g'		\
		${FILESDIR}/realplay.sh > ${WRKSRC}/realplay

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/realplay ${PREFIX}/bin
	${ECHO} bin/realplay >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
