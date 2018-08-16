# $NetBSD: Makefile,v 1.5 2018/08/16 18:55:09 adam Exp $

DISTNAME=	slurm-17.11.5
PKGNAME=	slurm-wlm-17.11.5
PKGREVISION=	2
CATEGORIES=	parallel
MASTER_SITES=	http://www.schedmd.com/download/archive/
MASTER_SITES+=	http://www.schedmd.com/download/latest/
MASTER_SITES+=	http://www.schedmd.com/download/development/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	bacon@NetBSD.org
HOMEPAGE=	http://www.schedmd.com/
COMMENT=	Simple Linux Utility for Resource Management

LICENSE=	gnu-gpl-v2

SUPERSEDES+=	slurm-2.6.4*

BUILD_DEPENDS+=	libtool-base-[0-9]*:../../devel/libtool-base
BUILD_DEPENDS+=	man2html-[0-9]*:../../textproc/man2html

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	bash perl pkg-config

CONFIG_SHELL=		bash
CONFIGURE_ARGS+=	--bindir=${PREFIX}/bin
CONFIGURE_ARGS+=	--htmldir=${PREFIX}/share/doc/${PKGNAME_NOREV}/html
CONFIGURE_ARGS+=	--with-munge=${BUILDLINK_PREFIX.munge}
CONFIGURE_ARGS+=	--with-hwloc=${PREFIX}
CONFIGURE_ARGS+=	--with-json=${PREFIX}
CONFIGURE_ARGS+=	--with-libssh2=${PREFIX}

LDFLAGS+=		-llz4

REPLACE_PYTHON=		doc/html/shtml2html.py
REPLACE_PYTHON+=	doc/man/man2html.py
REPLACE_PYTHON+=	testsuite/expect/regression.py
REPLACE_PYTHON+=	testsuite/expect/driveregress.py
REPLACE_PYTHON+=	contribs/cray/csm/slurmconfgen_smw.py

PKG_GROUPS=		slurm
PKG_USERS=		slurm:slurm

PKG_GECOS.slurm=	SLURM user
PKG_SHELL.slurm=	${NOLOGIN}

RCD_SCRIPTS+=		slurmd slurmctld

SUBST_CLASSES+=		linuxinit
SUBST_STAGE.linuxinit=	pre-configure
SUBST_FILES.linuxinit=	etc/init.d.slurm.in
SUBST_SED.linuxinit=	-e 's|^exec_prefix=|&${PREFIX}|'
SUBST_SED.linuxinit+=	-e 's|^prefix=|&${PREFIX}|'
SUBST_SED.linuxinit+=	-e 's|@bindir@|$${exec_prefix}/bin|'
SUBST_SED.linuxinit+=	-e 's|@sbindir@|$${exec_prefix}/sbin|'
SUBST_SED.linuxinit+=	-e 's|@libdir@|$${exec_prefix}/lib|'
SUBST_SED.linuxinit+=	-e 's|@sysconfdir@|$${prefix}/etc|'

# Configure flag to disable gtk does not work, so set an impossible requirement
SUBST_CLASSES+=		gtk
SUBST_STAGE.gtk=	pre-configure
SUBST_SED.gtk=		-e 's|min_gtk_version=.*|min_gtk_version=2000.0.0|'
SUBST_FILES.gtk=	configure

SUBST_CLASSES+=		make-ex
SUBST_STAGE.make-ex=	post-install
SUBST_FILES.make-ex=	etc/Makefile
SUBST_SED.make-ex=	-e 's|${WRKDIR}|<build-prefix>|g'

INSTALLATION_DIRS+=	share/examples/slurm

post-install:
	${RM} -f ${WRKSRC}/etc/init.d.slurm.in.orig
	${INSTALL_DATA} ${WRKSRC}/etc/* ${DESTDIR}${PREFIX}/share/examples/slurm

.include "../../www/curl/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../security/munge/buildlink3.mk" # optional
.include "../../parallel/hwloc/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../devel/hdf5/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../archivers/lz4/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../security/libssh2/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
