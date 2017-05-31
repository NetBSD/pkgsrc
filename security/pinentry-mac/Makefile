# $NetBSD: Makefile,v 1.1 2017/05/31 12:19:16 jym Exp $

DISTNAME=	pinentry-mac-${PINENTRY_VERSION}
MASTER_SITES=	${MASTER_SITE_GITHUB:=GPGTools/}
PINENTRY_VERSION=0.9.4
GITHUB_TAG=	v${PKGVERSION_NOREV}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/GPGTools/pinentry-mac/
COMMENT=	Application for entering PINs or Passphrases under Mac OS
LICENSE=	gnu-gpl-v3
CATEGORIES=	security

ONLY_FOR_PLATFORM=Darwin-*-*
USE_TOOLS=	pax

PINENTRY_APP_DIR=	${PREFIX}/libexec/${PINENTRY_APP_NAME}
PINENTRY_APP_NAME=	pinentry-mac.app
INSTALLATION_DIRS=	bin

FILES_SUBST+=	PINENTRY_APP_DIR=${PINENTRY_APP_DIR:Q}

SUBST_CLASSES+=         pinentry-mac-sh
SUBST_STAGE.pinentry-mac-sh=   pre-configure
SUBST_FILES.pinentry-mac-sh+=  ${WRKDIR}/pinentry-mac.sh
SUBST_VARS.pinentry-mac-sh+=   PINENTRY_APP_DIR
SUBST_MESSAGE.pinentry-mac-sh= Set path to the pinentry-mac .app directory.

post-extract:
	${CP} ${FILESDIR}/pinentry-mac.sh ${WRKDIR}

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PINENTRY_APP_DIR}
	cd ${WRKSRC}/build/Release/${PINENTRY_APP_NAME} && pax -rwpam . ${DESTDIR}${PINENTRY_APP_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/pinentry-mac.sh ${DESTDIR}${PREFIX}/bin/pinentry-mac

.include "../../mk/bsd.pkg.mk"
