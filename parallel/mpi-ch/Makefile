# $NetBSD: Makefile,v 1.73 2013/03/17 17:08:51 asau Exp $

DISTNAME=	mpich-3.0.1
CATEGORIES=	parallel
MASTER_SITES=	http://www.mpich.org/static/tarballs/$(PKGVERSION_NOREV)/

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.mpich.org/
COMMENT=	Open source MPI, MPI-2, and MPI-3 implementation from Univ. of Chicago

MAKE_JOBS_SAFE=		no

DEPENDS+=	bash-[0-9]*:../../shells/bash

# MPI_SUBPREFIX=		mpich
# MPI_PREFIX=		$(LOCALBASE)/$(MPI_SUBPREFIX)
MPI_PREFIX=		$(LOCALBASE)
INSTALLATION_PREFIX=	$(MPI_PREFIX)

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_LANGUAGES=		c c++ fortran77

PKG_SYSCONFSUBDIR=	mpich

GNU_CONFIGURE_PREFIX=	$(MPI_PREFIX)
CONFIGURE_ARGS+=	--datadir=$(MPI_PREFIX)/share/$(PKGBASE)
CONFIGURE_ARGS+=	--sysconfdir=$(PKG_SYSCONFDIR)
CONFIGURE_ARGS+=	--docdir=$(MPI_PREFIX)/share/doc/$(PKGBASE)
CONFIGURE_ARGS+=	--htmldir=$(MPI_PREFIX)/share/doc/$(PKGBASE)/html

CONFIGURE_ARGS+=	--with-pm=hydra:gforker
CONFIGURE_ARGS+=	--disable-fc		# problems?
CONFIGURE_ARGS+=	--with-openpa-prefix=$(BUILDLINK_PREFIX.openpa:Q) # reuse it
CONFIGURE_ARGS+=	--with-hwloc-prefix=$(BUILDLINK_PREFIX.hwloc:Q) # reuse it

USE_TOOLS+=		perl:run

BUILDLINK_PASSTHRU_RPATHDIRS+=	$(MPI_PREFIX)/lib

CONF_FILES+=		share/$(PKGBASE)/examples/mpicc.conf \
			$(PKG_SYSCONFDIR)/mpicc.conf
CONF_FILES+=		share/$(PKGBASE)/examples/mpicxx.conf \
			$(PKG_SYSCONFDIR)/mpicxx.conf
CONF_FILES+=		share/$(PKGBASE)/examples/mpif77.conf \
			$(PKG_SYSCONFDIR)/mpif77.conf

# FreeBSD 6 hack:
.include "../../mk/bsd.prefs.mk"
.if $(OPSYS) == "FreeBSD" || $(OPSYS) == "DragonFly"
BUILDLINK_TRANSFORM+=	rm:-lrt
.endif

.include "options.mk"

TEST_TARGET=	check

.include "../../parallel/hwloc/buildlink3.mk"
.include "../../parallel/openpa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
