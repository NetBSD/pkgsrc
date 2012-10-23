# $NetBSD: Makefile,v 1.3 2012/10/23 19:51:15 asau Exp $

DISTNAME=	netbsd-kmod-tools-5.1
CATEGORIES=	sysutils
DISTFILES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.NetBSD.org/
COMMENT=	NetBSD kmod tools

ONLY_FOR_PLATFORM=	NetBSD-5.[0-8]*-*

do-extract:
	mkdir ${WRKSRC}
	cp ${FILESDIR}/modstat.c ${WRKSRC}
	cp ${FILESDIR}/modload.c ${WRKSRC}
	cp ${FILESDIR}/modunload.c ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${CC} -Wall -Werror modstat.c -o modstat
	cd ${WRKSRC} && ${CC} -Wall -Werror modload.c -o modload -lprop
	cd ${WRKSRC} && ${CC} -Wall -Werror modunload.c -o modunload

do-install:
	${INSTALL_PROGRAM_DIR} ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/modstat ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/modload ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/modunload ${DESTDIR}${PREFIX}/sbin

.include "../../mk/bsd.pkg.mk"
