# $NetBSD: Makefile,v 1.3 2015/06/07 14:05:08 wiedi Exp $

DISTNAME=	iperf-3.0.11
PKGNAME=	${DISTNAME:S/iperf/iperf3/}
PKGREVISION=	1
CATEGORIES=	net benchmarks
MASTER_SITES=	http://downloads.es.net/pub/iperf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://software.es.net/iperf/
COMMENT=	TCP and UDP bandwidth performance measurement tool
LICENSE=	modified-bsd

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

LDFLAGS.SunOS+=		-lsocket -lnsl

.include "../../mk/bsd.pkg.mk"
