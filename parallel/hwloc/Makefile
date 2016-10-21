# $NetBSD: Makefile,v 1.19 2016/10/21 10:35:28 asau Exp $

DISTNAME=	hwloc-1.11.4
CATEGORIES=	parallel
MASTER_SITES=	http://www.open-mpi.org/software/hwloc/v1.11/downloads/

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.open-mpi.org/projects/hwloc/
COMMENT=	Portable Hardware Locality
LICENSE=	modified-bsd

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-picky

TEST_TARGET=	check

# libpci??
#.include "../../graphics/cairo/buildlink3.mk" # optional
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
