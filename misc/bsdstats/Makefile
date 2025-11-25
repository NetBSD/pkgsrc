# $NetBSD: Makefile,v 1.3 2025/11/25 07:09:36 wiz Exp $

DISTNAME=		bsdstats-5.3
CATEGORIES=		sysutils misc
MASTER_SITES=		# https://www.bsdstats.org/downloads/
DISTFILES=		# empty

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		https://www.bsdstats.org/
COMMENT=		BSD-Stats collector script

DEPENDS+=		netcat-[0-9]*:../../net/netcat

# XXX: Others might work
ONLY_FOR_PLATFORM=	NetBSD-*-* DragonFly-*-* FreeBSD-*-* OpenBSD-*-*

BUILD_DEFS+=		VARBASE

WRKSRC=			${WRKDIR}/bsdstats
NO_BUILD=		yes
INSTALLATION_DIRS=	bin

post-extract:
	${MKDIR} ${WRKDIR}/bsdstats
	${SED} -e "s!@PREFIX@!${PREFIX}!g" ${FILESDIR}/300.statistics \
		> ${WRKSRC}/300.statistics

do-install:
	${INSTALL} ${WRKSRC}/300.statistics ${DESTDIR}${PREFIX}/bin/300.statistics

.include "../../mk/bsd.pkg.mk"
