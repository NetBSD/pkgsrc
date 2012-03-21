# $NetBSD: Makefile,v 1.1.1.1 2012/03/21 13:31:35 asau Exp $

DISTNAME=	hwloc-1.4
CATEGORIES=	parallel
MASTER_SITES=	http://www.open-mpi.org/software/hwloc/v1.4/downloads/

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.open-mpi.org/projects/hwloc/
COMMENT=	Portable Hardware Locality
LICENCE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS=	pkg-config
USE_TOOLS+=	aclocal automake autoconf

CONFIGURE_ARGS+=	--enable-debug --enable-picky

TEST_TARGET=	check

pre-configure:
	$(RUN) cd $(WRKSRC) && autoreconf -ivf

# libpci??
#.include "../../graphics/cairo/buildlink3.mk" # optional
.include "../../textproc/libxml2/buildlink3.mk" # optional
.include "../../mk/curses.buildlink3.mk" # optional
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
