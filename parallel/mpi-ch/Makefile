# $NetBSD: Makefile,v 1.8 2000/03/02 23:47:33 wiz Exp $

DISTNAME=		mpich-1.1.1
CATEGORIES=		parallel
MASTER_SITES=		ftp://ftp.mcs.anl.gov/pub/mpi/old/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.mcs.anl.gov/mpi/mpich/index.html

DEPENDS+=		ssh-1.2.27:../../security/ssh

WRKSRC=			${WRKDIR}/mpich
ALL_TARGET=		ALL
USE_PERL5=		yes
HAS_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes
CONFIGURE_ARGS=		-prefix=${PREFIX} -arch=netbsd -comm=ch_p4
CONFIGURE_ARGS+=	-nof77 -make=${GMAKE} -mpe -rsh=ssh -opt=-O -nodevdebug

post-install:
	${RM} ${PREFIX}/mpiuninstall
	${RM} ${PREFIX}/man/mandesc
	${RMDIR} ${PREFIX}/share/doc/mpi

.include "../../mk/bsd.pkg.mk"
