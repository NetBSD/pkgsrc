# $NetBSD: Makefile,v 1.21.2.1 2003/12/07 16:36:49 agc Exp $

DISTNAME=		mpich-1.2.5-1a
PKGNAME=		mpich-1.2.5.1.1
PKGREVISION=		3
WRKSRC=			${WRKDIR}/${DISTNAME:C/-1a//}
CATEGORIES=		parallel
MASTER_SITES=		ftp://ftp.mcs.anl.gov/pub/mpi/
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} mpich-docs.tgz

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.mcs.anl.gov/mpi/mpich/index.html
COMMENT=		Free implementation of the Message Passing Interface

.if !exists(/usr/bin/ssh)
DEPENDS+=		{openssh-[0-9]*,ssh{,6}-1.2.27*}:../../security/ssh
.endif
DEPENDS+=		tk>=8.3.0:../../x11/tk

ALL_TARGET=		ALL examples
INSTALL_TARGET=		install-all
USE_PERL5=		yes
HAS_CONFIGURE=		yes
USE_X11=		yes

MPI_RSH?=		ssh

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS=		-prefix=${PREFIX}
CONFIGURE_ARGS+=	-docdir=${PREFIX}/share/doc/mpi-ch
CONFIGURE_ARGS+=	-htmldir=${PREFIX}/share/doc/html/mpi-ch
CONFIGURE_ARGS+=	-opt=-O
CONFIGURE_ARGS+=	--with-arch=netbsd
CONFIGURE_ARGS+=	--with-comm=ch_p4
CONFIGURE_ARGS+=	--with-mpe
CONFIGURE_ARGS+=	--disable-devdebug
CONFIGURE_ARGS+=	--disable-f90
CONFIGURE_ARGS+=	--disable-f90modules
.if !empty(CC_VERSION:Mgcc-3*)
CONFIGURE_ARGS+=	--disable-weak-symbols
.endif

MAKE_ENV+=		RSHCOMMAND="${MPI_RSH}"

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
	@(if [ -e ${WRKSRC}/mpe/viewers/jumpshot-2/bin/jumpshot ]; then \
		${TOUCH} ${WRKDIR}/with-java; \
	fi)
	${SED} -e "s,@PREFIX@,${PREFIX}," ${WRKSRC}/man/man1/MPI.1 >	\
			${WRKSRC}/man/man1/MPI.1.tmp
	${MV} ${WRKSRC}/man/man1/MPI.1.tmp ${WRKSRC}/man/man1/MPI.1

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

.include "../../mk/bsd.pkg.mk"

.if exists(${WRKDIR}/with-java)
PLIST_SRC+=		${PKGDIR}/PLIST.java
.endif
