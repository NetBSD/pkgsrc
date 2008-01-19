# $NetBSD: Makefile,v 1.53 2008/01/19 09:16:25 wiz Exp $

DISTNAME=		mpich-1.2.6
PKGREVISION=		6
CATEGORIES=		parallel
MASTER_SITES=		ftp://ftp.mcs.anl.gov/pub/mpi/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} mpich-docs.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www-unix.mcs.anl.gov/mpi/mpich1/
COMMENT=		Free implementation of the Message Passing Interface

# many failures
MAKE_JOBS_SAFE=		no

.if !exists(/usr/bin/ssh)
DEPENDS+=		{openssh-[0-9]*,ssh{,6}-1.2.27*}:../../security/openssh
.endif

BUILD_TARGET=		ALL examples
INSTALL_TARGET=		install-all
USE_LANGUAGES=		c c++ fortran
USE_TOOLS+=		perl:run
HAS_CONFIGURE=		yes
USE_FORTRAN=		yes
PKG_SYSCONFSUBDIR=	mpi-ch

MPI_RSH?=		ssh

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	-prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	-docdir=${PREFIX}/share/doc/mpi-ch
CONFIGURE_ARGS+=	-htmldir=${PREFIX}/share/doc/mpi-ch/html
CONFIGURE_ARGS+=	-mandir=${PREFIX}/${PKGMANDIR}
CONFIGURE_ARGS+=	-opt=-O
CONFIGURE_ARGS+=	-rsh=${MPI_RSH:Q}
CONFIGURE_ARGS+=	--with-comm=ch_p4
CONFIGURE_ARGS+=	--with-mpe
CONFIGURE_ARGS+=	--disable-devdebug
CONFIGURE_ARGS+=	--disable-f90
CONFIGURE_ARGS+=	--disable-f90modules
CONFIGURE_ENV+=		sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ENV+=		PERL=${PERL5:Q}
CONFIGURE_ENV+=		PERLFULLPATH=${PERL5:Q}

# build PATH in the config file is not a problem
CHECK_WRKREF_SKIP+=	share/examples/mpi-ch/perftest/config.system

PKG_SYSCONFSUBDIR=	mpi-ch
EGDIR=			${PREFIX}/share/examples/mpi-ch
CONF_FILES+=		${EGDIR}/mpichconf.h.dat ${PKG_SYSCONFDIR}/mpichconf.h.dat
CONF_FILES+=		${EGDIR}/mpichlib.conf ${PKG_SYSCONFDIR}/mpichlib.conf
CONF_FILES+=		${EGDIR}/mpichversion.c ${PKG_SYSCONFDIR}/mpichversion.c
CONF_FILES+=		${EGDIR}/mpif77.conf ${PKG_SYSCONFDIR}/mpif77.conf

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-arch=netbsd
PLIST_SUBST+=		MPICH_OPSYS=${LOWER_OPSYS:Q}
.elif ${OPSYS} == "DragonFly"
CONFIGURE_ARGS+=	--with-arch=freebsd
PLIST_SUBST+=		MPICH_OPSYS=freebsd
.elif ${OPSYS} == "IRIX"
CONFIGURE_ARGS+=	--with-arch=IRIX${ABI:S/32/N32/}
PLIST_SUBST+=		MPICH_OPSYS="${OPSYS}${ABI:S/32/N32/}"
.endif

.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-3*)
CONFIGURE_ARGS+=	--disable-weak-symbols
.endif

MAKE_ENV+=		RSHCOMMAND=${MPI_RSH:Q}

BUILD_DEFS+=		MPI_RSH

PLIST_SRC+=		${PKGDIR}/PLIST

post-extract:
	chmod -R g-w ${WRKDIR}/docs

pre-configure:
	set -e; for f in MPI-2-C++ examples/perftest/config/confdb mpe \
	    mpe/slog2sdk mpe/slog2sdk/trace_rlog mpe/slog2sdk/trace_sample\
	    mpid/ch_p4/p4 romio/confdb src/fortran/config; do \
		${RM} -f ${WRKSRC}/"$$f"/config.guess; \
		${CP} ${PKGSRCDIR}/mk/gnu-config/config.guess \
		    ${WRKSRC}/$$f; \
	done
	set -e; for f in MPI-2-C++ examples/perftest/config/confdb mpe \
	    mpe/slog2sdk mpe/slog2sdk/trace_rlog mpe/slog2sdk/trace_sample\
	    romio/confdb src/fortran/config; do \
		${RM} -f ${WRKSRC}/"$$f"/config.sub; \
		${CP} ${PKGSRCDIR}/mk/gnu-config/config.sub \
		    ${WRKSRC}/$$f; \
	done
.if ${MPI_RSH} == "rsh"
	@${ECHO} "======================================================================"
	@${ECHO} "Remember to enable 'shell' and 'login' in your /etc/inetd.conf and"
	@${ECHO} "restart inetd -- otherwise, the configure script will disable 'rsh'!"
	@${ECHO} "======================================================================"
	@sleep 3
.endif

post-build:
	@(if [ -r ${WRKSRC}/mpe/viewers/jumpshot-2/bin/jumpshot ]; then \
		${TOUCH} ${WRKDIR}/with-java; \
	fi)
	${SED} -e "s,@PREFIX@,${PREFIX}," ${WRKSRC}/man/man1/MPI.1 >	\
			${WRKSRC}/man/man1/MPI.1.tmp
	${MV} ${WRKSRC}/man/man1/MPI.1.tmp ${WRKSRC}/man/man1/MPI.1

post-patch:
	${RM} -f ${WRKSRC}/man/man1/MPI.1.orig

post-install:
	cd ${WRKDIR}/docs && ${PAX} -rw . ${PREFIX}/share/doc/mpi-ch/html
	@${RM} ${PREFIX}/${PKGMANDIR}/mandesc
	@${MV} ${PREFIX}/sbin/mpiuninstall ${PREFIX}/sbin/mpiuninstall.not
	@${CHMOD} 444 ${PREFIX}/sbin/mpiuninstall.not
	@${ECHO} "#!/bin/sh" > ${PREFIX}/sbin/mpiuninstall
	@${ECHO} "echo Please use the pkg_delete command to uninstall MPICH." \
	    >> ${PREFIX}/sbin/mpiuninstall
	@${ECHO} "echo The original mpiuninstall script is provided in" \
	    >> ${PREFIX}/sbin/mpiuninstall
	@${ECHO} "echo ${PREFIX}/sbin/mpiuninstall.not for reference." \
	    >> ${PREFIX}/sbin/mpiuninstall
	@${ECHO} "exit" >> ${PREFIX}/sbin/mpiuninstall
	@${CHMOD} 755 ${PREFIX}/sbin/mpiuninstall

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

.if exists(${WRKDIR}/with-java)
PLIST_SRC+=		${PKGDIR}/PLIST.java
.endif
