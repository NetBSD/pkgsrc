# $NetBSD: Makefile,v 1.4 2017/02/28 19:40:07 adam Exp $

DISTNAME=	iperf-3.1.6
PKGNAME=	${DISTNAME:S/iperf/iperf3/}
CATEGORIES=	net benchmarks
MASTER_SITES=	http://downloads.es.net/pub/iperf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://software.es.net/iperf/
COMMENT=	TCP and UDP bandwidth performance measurement tool
LICENSE=	modified-bsd

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
# sctp_bindx() is in headers, but unusable
CONFIGURE_ENV.NetBSD+=	ac_cv_header_netinet_sctp_h=no

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../mk/bsd.pkg.mk"
