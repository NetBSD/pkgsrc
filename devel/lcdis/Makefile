# $NetBSD: Makefile,v 1.3 2019/11/03 10:39:15 rillig Exp $

DISTNAME=	LCDISSRC
PKGNAME=	lcdis-1.04
CATEGORIES=	devel
MASTER_SITES=	https://travispaul.me/distfiles/
EXTRACT_SUFX=	.ZIP

MAINTAINER=		tpaul@NetBSD.org
HOMEPAGE=		https://web.archive.org/web/20110927100411/http://www.maushammer.com/vmu.html
COMMENT=		Disassembler for the Sega VMU/VMS
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		unzip

WRKSRC=			${WRKDIR}
DIST_SUBDIR=		${PKGNAME_NOREV}
INSTALLATION_DIRS=	bin

do-build:
	${CC} ${LDFLAGS} ${CFLAGS} -o ${WRKSRC}/lcdis ${WRKSRC}/LCDIS.C

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lcdis ${DESTDIR}${PREFIX}/bin/lcdis

.include "../../mk/bsd.pkg.mk"
