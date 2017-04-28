# $NetBSD: Makefile,v 1.21 2017/04/28 19:59:49 adam Exp $

DISTNAME=	hwloc-1.11.7
CATEGORIES=	parallel
MASTER_SITES=	http://www.open-mpi.org/software/hwloc/v1.11/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.open-mpi.org/projects/hwloc/
COMMENT=	Portable Hardware Locality
LICENSE=	modified-bsd

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-picky

TEST_TARGET=	check

# libpci??
#.include "../../graphics/cairo/buildlink3.mk" # optional
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
