# $NetBSD: Makefile,v 1.21 2013/12/17 15:05:23 tron Exp $

DISTNAME=	ttcp
PKGNAME=	${DISTNAME}-1.12
PKGREVISION=	2
CATEGORIES=	benchmarks net
#MASTER_SITES=	ftp://ftp.ptb.de/pub/benchmarks/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ccci.com/tools/ttcp/
COMMENT=	TCP testing and performance measuring tool
LICENSE=	public-domain

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BSD_MAKEFILE=	yes
USE_TOOLS+=		nroff
MAKE_ENV+=		NOGCCERROR=yes
WRKSRC=			${WRKDIR}

.include "../../mk/bsd.prefs.mk"

MANCOMPRESSED_IF_MANZ=	YES

#.if (${OPSYS} == Darwin)
#CFLAGS+=	"-Din_addr_t=\"unsigned long\""
#MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
#.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/cat1 ${PKGMANDIR}/man1

.if (${OPSYS} == SunOS)
do-build:
	cd ${WRKSRC} && \
	${CC} ttcp.c ${CFLAGS} ${LDFLAGS} -lsocket -lnsl -o ttcp && \
	nroff -man ttcp.1 >ttcp.cat1
.endif

.include "../../mk/bsd.pkg.mk"
