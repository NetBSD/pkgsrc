# $NetBSD: Makefile,v 1.19 2001/09/27 23:18:35 jlam Exp $

DISTNAME=		mpich-1.2.1
CATEGORIES=		parallel
MASTER_SITES=		ftp://ftp.mcs.anl.gov/pub/mpi/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.mcs.anl.gov/mpi/mpich/index.html
COMMENT=		Free implementation of the Message Passing Interface

.if !exists(/usr/bin/ssh)
DEPENDS+=		{openssh-[0-9]*,ssh{,6}-1.2.27*}:../../security/ssh
.endif
DEPENDS+=		tk>=8.3.0:../../x11/tk

ALL_TARGET=		ALL
USE_PERL5=		yes
HAS_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes
CONFIGURE_ARGS=		-prefix=${PREFIX} -arch=netbsd -comm=ch_p4
CONFIGURE_ARGS+=	-docdir=${PREFIX}/share/doc/mpi-ch
CONFIGURE_ARGS+=	-htmldir=${PREFIX}/share/doc/html/mpi-ch
CONFIGURE_ARGS+=	-make=${GMAKE} --with-mpe -rsh=ssh -opt=-O -nodevdebug
CONFIGURE_ARGS+=	--disable-f90 --disable-f90modules

.include "../../mk/bsd.prefs.mk"

PLIST_SRC+=		${PKGDIR}/PLIST

post-build:
	@(if [ -e ${WRKSRC}/mpe/viewers/jumpshot-2/bin/jumpshot ]; then \
		${TOUCH} ${WRKDIR}/with-java; \
	fi)

post-install:
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
