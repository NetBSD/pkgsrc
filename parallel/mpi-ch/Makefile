# $NetBSD: Makefile,v 1.5 1999/10/07 01:47:27 hubertf Exp $

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
	${RM} ${LOCALBASE}/mpiuninstall
	${RM} ${LOCALBASE}/man/mandesc

.include "../../mk/bsd.pkg.mk"
