# $NetBSD: Makefile,v 1.231 2019/10/11 02:02:04 kamil Exp $

DISTNAME=	thunderbird-${TB_VER}.source
PKGNAME=	thunderbird-${TB_VER}
TB_VER=		68.1.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_MOZILLA:=thunderbird/releases/${TB_VER}/source/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.thunderbird.net/en-US/
COMMENT=	Organize, secure and customize your mail
LICENSE=	mpl-1.1

USE_TOOLS+=	unzip pax
WRKSRC=		${WRKDIR}/${DISTNAME:S/.source//}
MOZILLA_DIR=	# empty
PLIST_SRC+=	${PLIST_SRC_DFLT}

CONFIG_GUESS_OVERRIDE+=	comm/ldap/sdks/c-sdk/config/autoconf/config.guess
CONFIG_SUB_OVERRIDE+=	comm/ldap/sdks/c-sdk/config/autoconf/config.sub

CONFIGURE_ARGS+=	--enable-application=comm/mail
# Disable WebRTC support for Thunderbird unconditionally.
CONFIGURE_ARGS+=	--disable-webrtc

NOT_PAX_MPROTECT_SAFE+=	lib/${MOZILLA}/${MOZILLA}
NOT_PAX_MPROTECT_SAFE+=	lib/${MOZILLA}/${MOZILLA}-bin

LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/${MOZILLA}

.include "../../mk/bsd.prefs.mk"

#SUBST_CLASSES+=			ext-compat
#SUBST_STAGE.ext-compat=		pre-configure
#SUBST_MESSAGE.ext-compat=	Fixing extension compatibility
#SUBST_FILES.ext-compat=		mailnews/extensions/enigmail/package/install.rdf
#SUBST_FILES.ext-compat+=	calendar/*/install.rdf
#SUBST_FILES.ext-compat+=	calendar/*/*/install.rdf
#SUBST_SED.ext-compat=		-e 's,\(<em:maxVersion>\).*<,\19.0<,g'

CHECK_WRKREF_SKIP+=lib/${MOZILLA}/chrome/toolkit/content/global/buildconfig.html

post-extract:
	${CP} ${FILESDIR}/cubeb_sun.c ${WRKSRC}/media/libcubeb/src/cubeb_sun.c
	mv ${WRKSRC}${MOZILLA_DIR}/gfx/ycbcr/yuv_row_arm.s \
		${WRKSRC}${MOZILLA_DIR}/gfx/ycbcr/yuv_row_arm.S

pre-configure:
	cd ${WRKSRC} && mkdir ${OBJDIR}
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoconf
	cd ${WRKSRC}${MOZILLA_DIR} && ${SETENV} ${CONFIGURE_ENV} autoconf
	cd ${WRKSRC}${MOZILLA_DIR}/js/src && ${SETENV} ${CONFIGURE_ENV} autoconf
	touch ${WRKSRC}/.mozconfig

do-build:
# XXX for some reason it doesn't work unless -j is explicitly specified
	cd ${WRKSRC}/${OBJDIR} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} -j${MAKE_JOBS:U1}

MOZILLA=	${PKGBASE}
MOZILLA_NAME=	${PKGBASE}
post-build:
	${SED} -e 's|@MOZILLA@|${MOZILLA}|g'				\
	  -e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|g'			\
	  -e 's|@MOZILLA_ICON@|${MOZILLA}.png|g'			\
	  < ${FILESDIR}/desktop.in					\
	  > ${WRKDIR}/desktop

INSTALLATION_DIRS+=	lib/${MOZILLA}/extensions
INSTALLATION_DIRS+=	share/applications share/pixmaps
post-install:
	${ECHO} '#! /bin/sh' > ${DESTDIR}${PREFIX}/bin/${MOZILLA}
	${ECHO} '${PREFIX}/lib/${MOZILLA}/${MOZILLA} "$$@"' >> \
		${DESTDIR}${PREFIX}/bin/${MOZILLA}
	${CHMOD} 755 ${DESTDIR}${PREFIX}/bin/${MOZILLA}
	${INSTALL_DATA} ${WRKDIR}/desktop				\
	  ${DESTDIR}${PREFIX}/share/applications/${MOZILLA}.desktop
	${INSTALL_DATA} ${WRKSRC}/${OBJDIR}/dist/${MOZILLA}/chrome/icons/default/default48.png	\
	  ${DESTDIR}${PREFIX}/share/pixmaps/${MOZILLA}.png

.include "../../www/firefox68/mozilla-common.mk"
.include "options.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
