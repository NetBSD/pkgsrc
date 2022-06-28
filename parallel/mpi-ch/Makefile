# $NetBSD: Makefile,v 1.96 2022/06/28 11:35:23 wiz Exp $

DISTNAME=	mpich-3.2.1
PKGREVISION=	9
CATEGORIES=	parallel
MASTER_SITES=	http://www.mpich.org/static/tarballs/${PKGVERSION_NOREV}/

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	https://www.mpich.org/
COMMENT=	Open source MPI, MPI-2, and MPI-3 implementation from Univ. of Chicago

CONFLICTS+=	openmpi-[0-9]*
DEPENDS+=	bash-[0-9]*:../../shells/bash

#MPI_SUBPREFIX=		mpich
#MPI_PREFIX=		${LOCALBASE}/${MPI_SUBPREFIX}
MPI_PREFIX=		${LOCALBASE}

OVERRIDE_DIRDEPTH=	3

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		perl:run
GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${MPI_PREFIX}
CONFIGURE_ARGS+=	--datadir=${MPI_PREFIX}/share/${PKGBASE}
CONFIGURE_ARGS+=	--docdir=${MPI_PREFIX}/share/doc/${PKGBASE}
CONFIGURE_ARGS+=	--htmldir=${MPI_PREFIX}/share/doc/${PKGBASE}/html
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-hwloc-prefix=${BUILDLINK_PREFIX.hwloc}
CONFIGURE_ARGS+=	--with-openpa-prefix=${BUILDLINK_PREFIX.openpa}
CONFIGURE_ARGS+=	--with-pm=hydra:gforker
CONFIGURE_ARGS+=	--with-thread-package=posix
CONFIGURE_ARGS+=	--enable-wrapper-rpath

LDFLAGS+=		-lm

PKG_SYSCONFSUBDIR=	mpich

BUILDLINK_PASSTHRU_RPATHDIRS+=	${MPI_PREFIX}/lib

# FreeBSD 6 hack:
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
BUILDLINK_TRANSFORM+=	rm:-lrt
.endif

.include "options.mk"

TEST_TARGET=	check

.include "../../parallel/hwloc/buildlink3.mk"
.include "../../parallel/openpa/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
