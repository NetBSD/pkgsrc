# $NetBSD: Makefile,v 1.34 2023/04/19 08:08:39 adam Exp $

DISTNAME=	hwloc-1.11.13
PKGREVISION=	7
CATEGORIES=	parallel
MASTER_SITES=	http://www.open-mpi.org/software/hwloc/v${PKGVERSION_NOREV:R}/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	https://www.open-mpi.org/projects/hwloc/
COMMENT=	Portable Hardware Locality
LICENSE=	modified-bsd

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-picky
CONFIGURE_ARGS+=	--disable-opencl
TEST_TARGET=		check

.include "../../mk/bsd.prefs.mk"

#.include "../../graphics/cairo/buildlink3.mk" # optional
.if ${OPSYS} != "Darwin"
# libpciaccess is marked as broken on Darwin
.include "../../sysutils/libpciaccess/buildlink3.mk"
.endif
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
