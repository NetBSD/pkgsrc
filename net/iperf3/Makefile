# $NetBSD: Makefile,v 1.22 2024/05/14 14:35:45 adam Exp $

DISTNAME=	iperf-3.17.1
PKGNAME=	${DISTNAME:S/iperf/iperf3/}
CATEGORIES=	net benchmarks
MASTER_SITES=	https://downloads.es.net/pub/iperf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://software.es.net/iperf/
COMMENT=	TCP and UDP bandwidth performance measurement tool
LICENSE=	modified-bsd

USE_CC_FEATURES=	c99
USE_LANGUAGES=		c
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS.NetBSD+=	--without-sctp
TEST_TARGET=		check

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../mk/atomic64.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
