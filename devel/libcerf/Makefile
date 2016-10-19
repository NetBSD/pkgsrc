# $NetBSD: Makefile,v 1.3 2016/10/19 12:14:08 wiz Exp $

DISTNAME=	libcerf-1.5
CATEGORIES=	math
MASTER_SITES=	http://apps.jcns.fz-juelich.de/src/libcerf/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.0rg
HOMEPAGE=	http://apps.jcns.fz-juelich.de/doku/sc/libcerf
COMMENT=	Library providing efficient and accurate complex error functions
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	perl:build gmake pkg-config

PKGCONFIG_OVERRIDE+=	libcerf.pc.in

.include "../../mk/bsd.pkg.mk"
