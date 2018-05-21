# $NetBSD: Makefile,v 1.1 2018/05/21 16:12:14 minskim Exp $

DISTNAME=	LCDISSRC
PKGNAME=	lcdis-1.04
CATEGORIES=	devel
MASTER_SITES=	https://travispaul.me/distfiles/
EXTRACT_SUFX=	.ZIP

MAINTAINER=		tr@vispaul.me
HOMEPAGE=		https://web.archive.org/web/20110927100411/http://www.maushammer.com/vmu.html
COMMENT=		Disassembler for the Sega VMU/VMS
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		unzip

WRKSRC=			${WRKDIR}
INSTALLATION_DIRS=	bin

do-build:
	${CC} ${LDFLAGS} ${CFLAGS} -o ${WRKSRC}/lcdis ${WRKSRC}/LCDIS.C

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lcdis ${DESTDIR}${PREFIX}/bin/lcdis

.include "../../mk/bsd.pkg.mk"
