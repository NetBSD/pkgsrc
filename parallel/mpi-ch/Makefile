# $NetBSD: Makefile,v 1.36 2005/06/11 11:22:21 wiz Exp $

DISTNAME=		mpich-1.2.6
CATEGORIES=		parallel
MASTER_SITES=		ftp://ftp.mcs.anl.gov/pub/mpi/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} mpich-docs.tgz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.mcs.anl.gov/mpi/mpich/index.html
COMMENT=		Free implementation of the Message Passing Interface

.if !exists(/usr/bin/ssh)
DEPENDS+=		{openssh-[0-9]*,ssh{,6}-1.2.27*}:../../security/openssh
.endif

BUILD_TARGET=		ALL examples
INSTALL_TARGET=		install-all
USE_PERL5=		yes
HAS_CONFIGURE=		yes
USE_FORTRAN=		yes
PKG_SYSCONFSUBDIR=	mpi-ch

MPI_RSH?=		ssh

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS=		-prefix=${PREFIX}
CONFIGURE_ARGS+=	-docdir=${PREFIX}/share/doc/mpi-ch
CONFIGURE_ARGS+=	-htmldir=${PREFIX}/share/doc/html/mpi-ch
CONFIGURE_ARGS+=	-opt=-O
CONFIGURE_ARGS+=	-rsh=${MPI_RSH}
CONFIGURE_ARGS+=	--with-comm=ch_p4
CONFIGURE_ARGS+=	--with-mpe
CONFIGURE_ARGS+=	--disable-devdebug
CONFIGURE_ARGS+=	--disable-f90
CONFIGURE_ARGS+=	--disable-f90modules
CONFIGURE_ENV+=		sysconfdir=${PKG_SYSCONFDIR}

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-arch=netbsd
PLIST_SUBST+=		MPICH_OPSYS="${LOWER_OPSYS}"
.elif ${OPSYS} == "IRIX"
CONFIGURE_ARGS+=	--with-arch=IRIX${ABI:S/32/N32/}
PLIST_SUBST+=		MPICH_OPSYS="${OPSYS}${ABI:S/32/N32/}"
.endif

.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-3*)
CONFIGURE_ARGS+=	--disable-weak-symbols
.endif

MAKE_ENV+=		RSHCOMMAND="${MPI_RSH}"

BUILD_DEFS+=		MPI_RSH

PLIST_SRC+=		${PKGDIR}/PLIST

.if ${MPI_RSH} == "rsh"
pre-configure:
	@${ECHO} "======================================================================";
	@${ECHO} "Remember to enable 'shell' and 'login' in your /etc/inetd.conf and";
	@${ECHO} "restart inetd -- otherwise, the configure script will disable 'rsh'!";
	@${ECHO} "======================================================================";
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
	cd ${WRKDIR}/docs && ${PAX} -rw . ${PREFIX}/share/doc/html/mpi-ch/
	@${RM} ${PREFIX}/man/mandesc
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

.include "../../x11/tk83/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

.if exists(${WRKDIR}/with-java)
PLIST_SRC+=		${PKGDIR}/PLIST.java
.endif
