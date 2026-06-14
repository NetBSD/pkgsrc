# $NetBSD: Makefile,v 1.20 2026/06/14 08:30:30 drixter Exp $

DISTNAME=	6tunnel-0.14
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=wojtekka/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/wojtekka/6tunnel
COMMENT=	Tunnelling for applications that don't speak IPv6
LICENSE=	gnu-gpl-v2

LDFLAGS.SunOS+=	-lsocket -lnsl

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

GNU_CONFIGURE=	yes

.include "../../mk/bsd.pkg.mk"
