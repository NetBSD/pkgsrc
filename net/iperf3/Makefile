# $NetBSD: Makefile,v 1.15 2023/02/18 20:19:21 adam Exp $

DISTNAME=	iperf-3.13
PKGNAME=	${DISTNAME:S/iperf/iperf3/}
CATEGORIES=	net benchmarks
MASTER_SITES=	https://downloads.es.net/pub/iperf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://software.es.net/iperf/
COMMENT=	TCP and UDP bandwidth performance measurement tool
LICENSE=	modified-bsd

USE_LANGUAGES=		c99
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS.NetBSD+=	--without-sctp
TEST_TARGET=		check

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
