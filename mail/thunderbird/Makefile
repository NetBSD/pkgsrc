# $NetBSD: Makefile,v 1.119 2013/08/10 00:31:20 ryoon Exp $
#

DISTNAME=	# empty
PKGNAME=	thunderbird-${TB_VER}
TB_VER=		17.0.8
LIGHTNINGVER=	1.9
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_MOZILLA_ESR:=thunderbird/releases/${TB_VER}esr/source/} \
		${MASTER_SITE_MOZILLA_ALL:=thunderbird/releases/${TB_VER}esr/source/}
DISTFILES=	thunderbird-${TB_VER}esr.source.tar.bz2 \
		lightning-${LIGHTNINGVER}.source.tar.bz2
SITES.lightning-${LIGHTNINGVER}.source.tar.bz2=	${MASTER_SITE_MOZILLA:=calendar/lightning/releases/${LIGHTNINGVER}/source/}
EXTRACT_DIR.lightning-${LIGHTNINGVER}.source.tar.bz2=	${WRKSRC}/lightning

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mozillamessaging.com/en-US/thunderbird/
COMMENT=	Organize, secure and customize your mail

USE_TOOLS+=	unzip pax
WRKSRC=		${WRKDIR}/comm-esr17
MOZILLA_DIR=	mozilla/
PLIST_SRC+=	${PLIST_SRC_DFLT}

CONFIG_GUESS_OVERRIDE+=	ldap/sdks/c-sdk/config/autoconf/config.guess
CONFIG_SUB_OVERRIDE+=	ldap/sdks/c-sdk/config/autoconf/config.sub

CONFIGURE_ARGS+=	--enable-application=mail

ALL_ENV+=		MOZILLA_PKG_NAME=thunderbird

.include "../../mk/bsd.prefs.mk"

#SUBST_CLASSES+=			ext-compat
#SUBST_STAGE.ext-compat=		pre-configure
#SUBST_MESSAGE.ext-compat=	Fixing extension compatibility
#SUBST_FILES.ext-compat=		mailnews/extensions/enigmail/package/install.rdf
#SUBST_FILES.ext-compat+=	calendar/*/install.rdf
#SUBST_FILES.ext-compat+=	calendar/*/*/install.rdf
#SUBST_SED.ext-compat=		-e 's,\(<em:maxVersion>\).*<,\19.0<,g'

post-extract:
	cd ${WRKSRC} && ${RM} -r calendar
	${CP} -r ${EXTRACT_DIR.lightning-${LIGHTNINGVER}.source.tar.bz2}/comm-beta/calendar ${WRKSRC}
	${RM} -r ${EXTRACT_DIR.lightning-${LIGHTNINGVER}.source.tar.bz2}

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoconf
	cd ${WRKSRC}/mozilla && ${SETENV} ${CONFIGURE_ENV} autoconf
	cd ${WRKSRC}/mozilla/js/src && ${SETENV} ${CONFIGURE_ENV} autoconf
	cd ${WRKSRC}/mozilla/nsprpub && ${SETENV} ${CONFIGURE_ENV} autoconf
	cd ${WRKSRC}/ldap/sdks/c-sdk && ${SETENV} ${CONFIGURE_ENV} autoconf

do-build:
# XXX for some reason it doesn't work unless -j is explicitly specified
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} -j${MAKE_JOBS:U1}

MOZILLA=thunderbird
MOZILLA_NAME=Thunderbird
post-build:
	${SED} -e 's|@MOZILLA@|${MOZILLA}|g'				\
	  -e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|g'			\
	  -e 's|@MOZILLA_ICON@|${MOZILLA}.png|g'			\
	  < ${FILESDIR}/desktop.in					\
	  > ${WRKDIR}/desktop

INSTALLATION_DIRS+=	share/applications share/pixmaps
post-install:
	${INSTALL_DATA} ${WRKDIR}/desktop				\
	  ${DESTDIR}${PREFIX}/share/applications/${MOZILLA}.desktop
	${INSTALL_DATA} ${WRKSRC}/mozilla/dist/thunderbird/chrome/icons/default/default48.png	\
	  ${DESTDIR}${PREFIX}/share/pixmaps/${MOZILLA}.png
	@${STEP_MSG} "Installing bundled thunderbird extensions."
	${TOUCH} ${TOUCH_FLAGS} ${DESTDIR}${PREFIX}/include/thunderbird/mozilla/throw_gcc.h
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

.include "../../devel/xulrunner17/mozilla-common.mk"
.include "options.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
