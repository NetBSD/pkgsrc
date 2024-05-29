# $NetBSD: Makefile,v 1.30 2024/05/29 16:33:25 adam Exp $

DISTNAME=	thunderbird-${TB_VER}.source
PKGNAME=	thunderbird68-${TB_VER}
PKGREVISION=	26
TB_VER=		68.12.0
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

ALL_ENV+=	MOZ_APP_NAME=${MOZILLA_NAME}

CONFIG_GUESS_OVERRIDE+=	comm/ldap/sdks/c-sdk/config/autoconf/config.guess
CONFIG_SUB_OVERRIDE+=	comm/ldap/sdks/c-sdk/config/autoconf/config.sub

CONFIGURE_ARGS+=	--enable-application=comm/mail
# Disable WebRTC support for Thunderbird unconditionally.
CONFIGURE_ARGS+=	--disable-webrtc
CONFIGURE_ARGS+=	--with-app-name=${MOZILLA_NAME}

NOT_PAX_MPROTECT_SAFE+=	lib/${MOZILLA_NAME}/${MOZILLA_NAME}
NOT_PAX_MPROTECT_SAFE+=	lib/${MOZILLA_NAME}/${MOZILLA_NAME}-bin

LDFLAGS+=		${COMPILER_RPATH_FLAG}${PREFIX}/lib/${MOZILLA_NAME}

.include "../../mk/bsd.prefs.mk"

CHECK_WRKREF_SKIP+=	lib/${MOZILLA_NAME}/chrome/toolkit/content/global/buildconfig.html
CHECK_WRKREF_SKIP+=	lib/${MOZILLA_NAME}/chrome/messenger/content/messenger/buildconfig.html

post-extract:
	${CP} ${FILESDIR}/cubeb_sun.c ${WRKSRC}/media/libcubeb/src/cubeb_sun.c

pre-configure:
	cd ${WRKSRC} && mkdir ${OBJDIR}
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoconf-2.13
	cd ${WRKSRC}${MOZILLA_DIR} && ${SETENV} ${CONFIGURE_ENV} autoconf-2.13
	cd ${WRKSRC}${MOZILLA_DIR}/js/src && ${SETENV} ${CONFIGURE_ENV} autoconf-2.13
	touch ${WRKSRC}/.mozconfig

do-build:
# XXX for some reason it doesn't work unless -j is explicitly specified
	${_ULIMIT_CMD} cd ${WRKSRC}/${OBJDIR} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} -j${MAKE_JOBS:U1}

MOZILLA=	thunderbird
MOZILLA_NAME=	${PKGBASE}
post-build:
	${SED} -e 's|@MOZILLA@|${MOZILLA}|g'				\
	  -e 's|@MOZILLA_NAME@|${MOZILLA_NAME}|g'			\
	  -e 's|@MOZILLA_ICON@|${MOZILLA_NAME}.png|g'			\
	  < ${FILESDIR}/desktop.in					\
	  > ${WRKDIR}/desktop

INSTALLATION_DIRS+=	lib/${MOZILLA_NAME}/extensions
INSTALLATION_DIRS+=	share/applications share/pixmaps
post-install:
	${ECHO} '#! /bin/sh' > ${DESTDIR}${PREFIX}/bin/${MOZILLA_NAME}
	${ECHO} '${PREFIX}/lib/${MOZILLA_NAME}/${MOZILLA_NAME} "$$@"' >> \
		${DESTDIR}${PREFIX}/bin/${MOZILLA_NAME}
	${CHMOD} 755 ${DESTDIR}${PREFIX}/bin/${MOZILLA_NAME}
	${INSTALL_DATA} ${WRKDIR}/desktop				\
	  ${DESTDIR}${PREFIX}/share/applications/${MOZILLA_NAME}.desktop
	${INSTALL_DATA} ${WRKSRC}/${OBJDIR}/dist/${MOZILLA_NAME}/chrome/icons/default/default48.png	\
	  ${DESTDIR}${PREFIX}/share/pixmaps/${MOZILLA_NAME}.png

.include "mozilla-common.mk"
.include "options.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
