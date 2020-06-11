# $NetBSD: Makefile,v 1.9 2020/06/11 17:12:43 adam Exp $

DISTNAME=	iperf-3.8.1
PKGNAME=	${DISTNAME:S/iperf/iperf3/}
CATEGORIES=	net benchmarks
MASTER_SITES=	http://downloads.es.net/pub/iperf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://software.es.net/iperf/
COMMENT=	TCP and UDP bandwidth performance measurement tool
LICENSE=	modified-bsd

USE_LANGUAGES=		c99
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
#CONFIGURE_ARGS+=	--disable-profiling
CONFIGURE_ARGS.NetBSD+=	--without-sctp
# sctp_bindx() is in headers, but unusable
#CONFIGURE_ENV.NetBSD+=	ac_cv_header_netinet_sctp_h=no
TEST_TARGET=		check

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
