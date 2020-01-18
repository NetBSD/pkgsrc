# $NetBSD: Makefile,v 1.7 2020/01/18 21:50:15 jperkin Exp $

DISTNAME=	iperf-3.7
PKGNAME=	${DISTNAME:S/iperf/iperf3/}
PKGREVISION=	1
CATEGORIES=	net benchmarks
MASTER_SITES=	http://downloads.es.net/pub/iperf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://software.es.net/iperf/
COMMENT=	TCP and UDP bandwidth performance measurement tool
LICENSE=	modified-bsd

USE_LANGUAGES=		c99
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-profiling
# sctp_bindx() is in headers, but unusable
CONFIGURE_ENV.NetBSD+=	ac_cv_header_netinet_sctp_h=no
TEST_TARGET=		check

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
