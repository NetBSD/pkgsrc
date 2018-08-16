# $NetBSD: Makefile,v 1.23 2018/08/16 12:56:27 adam Exp $

DISTNAME=	hwloc-1.11.10
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

.include "../../mk/bsd.prefs.mk"

# libpci??
#.include "../../graphics/cairo/buildlink3.mk" # optional
.if ${OPSYS} != "Darwin"
# libpciaccess is marked as broken on Darwin
.include "../../sysutils/libpciaccess/buildlink3.mk"
.endif
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
