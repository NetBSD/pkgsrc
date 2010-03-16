# $NetBSD: Makefile,v 1.50 2010/03/16 10:59:09 tnn Exp $
#

DISTNAME=	thunderbird-${TB_VER}.source
PKGNAME=	thunderbird-${TB_VER}
TB_VER=		3.0.2
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_MOZILLA:=thunderbird/releases/${TB_VER}/source/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	http://www.mozillamessaging.com/en-US/thunderbird/
COMMENT=	Organize, secure and customize your mail

WRKSRC=		${WRKDIR}/comm-1.9.1
MOZILLA_DIR=	mozilla/

CONFIG_GUESS_OVERRIDE+=	directory/c-sdk/config/autoconf/config.guess
CONFIG_SUB_OVERRIDE+=	directory/c-sdk/config/autoconf/config.sub

CONFIGURE_ARGS+=	--enable-application=mail
CONFIGURE_ARGS+=	--enable-static

ALL_ENV+=		MOZILLA_PKG_NAME=thunderbird

pre-configure:
	cd ${WRKSRC}/directory/c-sdk && ${SETENV} ${CONFIGURE_ENV} autoconf
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} autoconf
	cd ${WRKSRC}/mozilla && ${SETENV} ${CONFIGURE_ENV} autoconf
	cd ${WRKSRC}/mozilla/js/src && ${SETENV} ${CONFIGURE_ENV} autoconf
	cd ${WRKSRC}/mozilla/nsprpub && ${SETENV} ${CONFIGURE_ENV} autoconf
	cd ${WRKSRC}/directory/c-sdk && ${SETENV} ${CONFIGURE_ENV} autoconf

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
	${INSTALL_DATA} ${WRKSRC}/mail/branding/nightly/mailicon48.png	\
	  ${DESTDIR}${PREFIX}/share/pixmaps/${MOZILLA}.png

.include "../../devel/xulrunner/mozilla-common.mk"
.include "options.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
