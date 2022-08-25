# $NetBSD: Makefile,v 1.99 2022/08/25 21:46:53 thor Exp $

DISTNAME=	mpich-3.4.3
CATEGORIES=	parallel
MASTER_SITES=	http://www.mpich.org/static/tarballs/${PKGVERSION_NOREV}/

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	https://www.mpich.org/
COMMENT=	Open source MPI, MPI-2, and MPI-3 implementation from Univ. of Chicago
LICENSE=	0-clause-bsd

CONFLICTS+=	openmpi-[0-9]*
DEPENDS+=	bash-[0-9]*:../../shells/bash

OVERRIDE_DIRDEPTH=	3

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		perl:run
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/${PKGBASE}
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc/${PKGBASE}
CONFIGURE_ARGS+=	--htmldir=${PREFIX}/share/doc/${PKGBASE}/html
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
# Use internal hwloc until we decided to upgrade to 2.x in pkgsrc.
#CONFIGURE_ARGS+=	--with-hwloc-prefix=${BUILDLINK_PREFIX.hwloc}
CONFIGURE_ARGS+=	--with-openpa-prefix=${BUILDLINK_PREFIX.openpa}
CONFIGURE_ARGS+=	--with-pm=hydra:gforker
# Future:  --with-device=ch4:ofi or --with-device=ch4:ucx
# After adding ucx library to pkgsrc, probably.
CONFIGURE_ARGS+=	--with-device=ch3
CONFIGURE_ARGS+=	--with-thread-package=posix
CONFIGURE_ARGS+=	--enable-wrapper-rpath

LDFLAGS+=		-lm

PKG_SYSCONFSUBDIR=	mpich

# FreeBSD 6 hack:
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
BUILDLINK_TRANSFORM+=	rm:-lrt
.endif

# These contain strings with build info, for display with the "-info"
# argument.
CHECK_WRKREF_SKIP+=	bin/mpiexec
CHECK_WRKREF_SKIP+=	bin/mpiexec.hydra
CHECK_WRKREF_SKIP+=	bin/mpirun

.include "options.mk"

TEST_TARGET=	check

# Re-enable when at version 2.x.
#.include "../../parallel/hwloc/buildlink3.mk"
.include "../../parallel/openpa/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
