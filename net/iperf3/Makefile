# $NetBSD: Makefile,v 1.5 2017/04/28 14:12:14 jperkin Exp $

DISTNAME=	iperf-3.1.6
PKGNAME=	${DISTNAME:S/iperf/iperf3/}
CATEGORIES=	net benchmarks
MASTER_SITES=	http://downloads.es.net/pub/iperf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://software.es.net/iperf/
COMMENT=	TCP and UDP bandwidth performance measurement tool
LICENSE=	modified-bsd

USE_LANGUAGES=		c99
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
# sctp_bindx() is in headers, but unusable
CONFIGURE_ENV.NetBSD+=	ac_cv_header_netinet_sctp_h=no

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../mk/bsd.pkg.mk"
