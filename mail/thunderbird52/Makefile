# $NetBSD: Makefile,v 1.12 2020/06/02 08:24:15 adam Exp $

DISTNAME=	thunderbird-${TB_VER}.source
PKGNAME=	thunderbird${TB_VER:C/\..*$//}-${TB_VER}
PKGREVISION=	10
TB_VER=		52.9.1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_MOZILLA:=thunderbird/releases/${TB_VER}/source/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.thunderbird.net/en-US/
COMMENT=	Organize, secure and customize your mail
LICENSE=	mpl-1.1

USE_TOOLS+=	unzip pax
WRKSRC=		${WRKDIR}/${DISTNAME:S/.source//}
MOZILLA_DIR=	mozilla/
PLIST_SRC+=	${PLIST_SRC_DFLT}

CONFIG_GUESS_OVERRIDE+=	ldap/sdks/c-sdk/config/autoconf/config.guess
CONFIG_SUB_OVERRIDE+=	ldap/sdks/c-sdk/config/autoconf/config.sub

CONFIGURE_ARGS+=	--enable-application=mail
# Disable WebRTC support for Thunderbird unconditionally.
CONFIGURE_ARGS+=	--disable-webrtc

NOT_PAX_MPROTECT_SAFE+=	lib/${PKGBASE}/thunderbird
NOT_PAX_MPROTECT_SAFE+=	lib/${PKGBASE}/thunderbird-bin

ALL_ENV+=		MOZILLA_PKG_NAME=${PKGBASE}

LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/${PKGBASE}

.include "../../mk/bsd.prefs.mk"

#SUBST_CLASSES+=		ext-compat
#SUBST_STAGE.ext-compat=	pre-configure
#SUBST_MESSAGE.ext-compat=	Fixing extension compatibility
#SUBST_FILES.ext-compat=	mailnews/extensions/enigmail/package/install.rdf
#SUBST_FILES.ext-compat+=	calendar/*/install.rdf
#SUBST_FILES.ext-compat+=	calendar/*/*/install.rdf
#SUBST_SED.ext-compat=		-e 's,\(<em:maxVersion>\).*<,\19.0<,g'

SUBST_CLASSES+=		sys-dic
SUBST_STAGE.sys-dic=	pre-configure
SUBST_MESSAGE.sys-dic=	Reference to system hunspell dictionaries.
SUBST_FILES.sys-dic=	mozilla/extensions/spellcheck/hunspell/glue/mozHunspell.cpp
SUBST_VARS.sys-dic=	LOCALBASE

CHECK_WRKREF_SKIP+=	lib/${PKGBASE}/chrome/toolkit/content/global/buildconfig.html

post-extract:
	mv ${WRKSRC}/mozilla/gfx/ycbcr/yuv_row_arm.s \
		${WRKSRC}/mozilla/gfx/ycbcr/yuv_row_arm.S

pre-configure:
	cd ${WRKSRC} && mkdir ${OBJDIR}
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoconf
	cd ${WRKSRC}/mozilla && ${SETENV} ${CONFIGURE_ENV} autoconf
	cd ${WRKSRC}/mozilla/js/src && ${SETENV} ${CONFIGURE_ENV} autoconf
	touch ${WRKSRC}/.mozconfig

do-build:
# XXX for some reason it doesn't work unless -j is explicitly specified
	${RUN} ${_ULIMIT_CMD} cd ${WRKSRC}/${OBJDIR} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} -j${MAKE_JOBS:U1}

MOZILLA=	${PKGBASE}
MOZILLA_NAME=	${PKGBASE}
post-build:
	${SED} -e 's|@MOZILLA@|${MOZILLA}|g'				\
	  -e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|g'			\
	  -e 's|@MOZILLA_ICON@|${MOZILLA}.png|g'			\
	  < ${FILESDIR}/desktop.in					\
	  > ${WRKDIR}/desktop

INSTALLATION_DIRS+=	lib/${PKGBASE}/extensions
INSTALLATION_DIRS+=	share/applications share/pixmaps
post-install:
	${INSTALL_DATA} ${WRKDIR}/desktop				\
	  ${DESTDIR}${PREFIX}/share/applications/${MOZILLA}.desktop
	${INSTALL_DATA} ${WRKSRC}/${OBJDIR}/dist/thunderbird/chrome/icons/default/default48.png	\
	  ${DESTDIR}${PREFIX}/share/pixmaps/${MOZILLA}.png
	@${STEP_MSG} "Installing bundled thunderbird extensions."
	rm -rf ${WRKDIR}/extensions
	${MKDIR} ${WRKDIR}/extensions
	${RUN} for e in ${XPI_FILES}; do				\
	  subdir="`${UNZIP_CMD} -c "$$e" install.rdf | awk '/^    <em:id>/ {sub(".*<em:id>","");sub("</em:id>.*","");print;exit;}'`" &&	\
	  ${MKDIR} "${WRKDIR}/extensions/$$subdir" &&			\
	  cd "${WRKDIR}/extensions/$$subdir" &&				\
	  ${UNZIP_CMD} -aqo $$e;					\
	done
	cd ${WRKDIR}/extensions && pax -rw .				\
	   ${DESTDIR}${PREFIX}/lib/${MOZILLA}/extensions/.
	rm -rf ${WRKDIR}/extensions

.include "../../www/firefox52/mozilla-common.mk"
.include "options.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
