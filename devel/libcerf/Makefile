# $NetBSD: Makefile,v 1.11 2023/01/24 18:36:23 wiz Exp $

DISTNAME=	libcerf-1.13
CATEGORIES=	devel math
MASTER_SITES=	http://apps.jcns.fz-juelich.de/src/libcerf/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jugit.fz-juelich.de/mlz/libcerf
COMMENT=	Library providing efficient and accurate complex error functions
LICENSE=	mit

USE_LANGUAGES=		c99
USE_TOOLS+=		pod2man
PKGCONFIG_OVERRIDE=	libcerf.pc.in
TEST_TARGET=		test

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
