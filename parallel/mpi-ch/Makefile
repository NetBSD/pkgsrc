# $NetBSD: Makefile,v 1.62 2010/02/10 19:17:44 joerg Exp $

DISTNAME=	mpich2-1.2.1
PKGREVISION=	1
CATEGORIES=	parallel
MASTER_SITES=	http://www.mcs.anl.gov/research/projects/mpich2/downloads/tarballs/1.2.1/

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://www.mcs.anl.gov/research/projects/mpich2/
COMMENT=	Open source MPI and MPI-2 implementation from Univ. of Chicago

CONFLICTS+=	musicpd-[0-9]*	# installs bin/mpd
CONFLICTS+=	mpich-[0-9]*	# installs bin/mpicc & other wrappers
CONFLICTS+=	openmpi-[0-9]*	# installs bin/mpicc & other wrappers

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++ fortran

PKG_SYSCONFSUBDIR=	mpich

CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/${PKGBASE}
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--docdir=${PREFIX}/share/doc/${PKGBASE}
CONFIGURE_ARGS+=	--htmldir=${PREFIX}/share/doc/${PKGBASE}/html

CONFIGURE_ARGS+=	--disable-f90	# problems?

USE_TOOLS+=		perl:run

REPLACE_PYTHON+=	src/pm/mpd/*.py src/pm/mpd/test/*.py

CONF_FILES+=		share/${PKGBASE}/examples/mpe_callstack_ldflags.conf \
			${PKG_SYSCONFDIR}/mpe_callstack_ldflags.conf
CONF_FILES+=		share/${PKGBASE}/examples/mpe_f77env.conf \
			${PKG_SYSCONFDIR}/mpe_f77env.conf
CONF_FILES+=		share/${PKGBASE}/examples/mpe_help.conf \
			${PKG_SYSCONFDIR}/mpe_help.conf
CONF_FILES+=		share/${PKGBASE}/examples/mpe_log.conf \
			${PKG_SYSCONFDIR}/mpe_log.conf
CONF_FILES+=		share/${PKGBASE}/examples/mpe_log_postlib.conf \
			${PKG_SYSCONFDIR}/mpe_log_postlib.conf
CONF_FILES+=		share/${PKGBASE}/examples/mpe_mpicheck.conf \
			${PKG_SYSCONFDIR}/mpe_mpicheck.conf
CONF_FILES+=		share/${PKGBASE}/examples/mpe_mpilog.conf \
			${PKG_SYSCONFDIR}/mpe_mpilog.conf
CONF_FILES+=		share/${PKGBASE}/examples/mpe_mpitrace.conf \
			${PKG_SYSCONFDIR}/mpe_mpitrace.conf
CONF_FILES+=		share/${PKGBASE}/examples/mpe_nolog.conf \
			${PKG_SYSCONFDIR}/mpe_nolog.conf

CONF_FILES+=		share/${PKGBASE}/examples/mpicc.conf \
			${PKG_SYSCONFDIR}/mpicc.conf
CONF_FILES+=		share/${PKGBASE}/examples/mpicxx.conf \
			${PKG_SYSCONFDIR}/mpicxx.conf
CONF_FILES+=		share/${PKGBASE}/examples/mpif77.conf \
			${PKG_SYSCONFDIR}/mpif77.conf
CONF_FILES+=		share/${PKGBASE}/examples/mpixxx_opts.conf \
			${PKG_SYSCONFDIR}/mpixxx_opts.conf

# disable bundled OpenPA:
post-extract:
	mv $(WRKSRC)/src/openpa $(WRKSRC)/src/openpa.off

.include "../../mk/bsd.prefs.mk"

# FreeBSD 6 hack:
.if $(OPSYS) == "FreeBSD" || $(OPSYS) == "DragonFly"
BUILDLINK_TRANSFORM+=	rm:-lrt
.endif

.include "../../lang/python/application.mk"
.include "../../parallel/openpa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
