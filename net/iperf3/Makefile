# $NetBSD: Makefile,v 1.11 2021/05/29 06:16:56 adam Exp $

DISTNAME=	iperf-3.10
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
