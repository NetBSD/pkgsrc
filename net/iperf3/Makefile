# $NetBSD: Makefile,v 1.2 2015/02/07 17:11:23 he Exp $

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

.include "../../mk/bsd.pkg.mk"
