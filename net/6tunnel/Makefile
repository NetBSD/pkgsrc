# $NetBSD: Makefile,v 1.19 2025/04/21 21:01:38 wiz Exp $

DISTNAME=	6tunnel-0.13
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=wojtekka/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/wojtekka/6tunnel
COMMENT=	Tunnelling for applications that don't speak IPv6
LICENSE=	gnu-gpl-v2

LDFLAGS.SunOS+=	-lsocket -lnsl

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	${CC} ${CFLAGS} -o ${WRKSRC}/6tunnel ${WRKSRC}/6tunnel.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/6tunnel ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/6tunnel.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
