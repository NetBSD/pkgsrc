# $NetBSD: Makefile,v 1.1 2022/01/05 10:56:00 schmonz Exp $

DISTNAME=		sleepwatcher_2.2.1
PKGNAME=		${DISTNAME:S/_/-/}
CATEGORIES=		sysutils
MASTER_SITES=		${HOMEPAGE}
EXTRACT_SUFX=		.tgz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://www.bernhard-baehr.de/
COMMENT=		Run a Unix command on macOS sleep or wake events
LICENSE=		gnu-gpl-v3

ONLY_FOR_PLATFORM=	Darwin-*-*

BUILD_DIRS=		sources
BUILD_TARGET=		${PKGBASE}

RCD_SCRIPTS=		sleepwatcher

REPLACE_SH+=		config/rc.sleep config/rc.wakeup

post-extract:
	cd ${WRKSRC} && rm -f sleepwatcher && mv sleepwatcher.8 sources

post-install:
	cd ${WRKSRC}/config && \
	${INSTALL_SCRIPT} rc.sleep ${DESTDIR}${PREFIX}/sbin/sleepwatcher-sleep && \
	${INSTALL_SCRIPT} rc.wakeup ${DESTDIR}${PREFIX}/sbin/sleepwatcher-wakeup

.include "../../mk/bsd.pkg.mk"
