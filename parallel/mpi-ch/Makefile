# $NetBSD: Makefile,v 1.2 1999/03/08 10:48:29 agc Exp $

DISTNAME=		mpich
PKGNAME=		mpich-1.1.1
CATEGORIES=		parallel
MASTER_SITES=		ftp://ftp.mcs.anl.gov/pub/mpi/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.mcs.anl.gov/mpi/mpich/index.html

DEPENDS+=		ssh-1.2.26:../../security/ssh

WRKSRC=			${WRKDIR}/mpich
ALL_TARGET=		ALL
USE_PERL5=		yes
HAS_CONFIGURE=		yes
USE_GMAKE=		yes
USE_X11=		yes
CONFIGURE_ARGS=		-prefix=${PREFIX} -arch=${LOWER_OPSYS} -comm=ch_p4
CONFIGURE_ARGS+=	-nof77 -make=${GMAKE} -mpe -rsh=ssh -opt=-O -nodevdebug

post-install:
	${RM} ${LOCALBASE}/mpiuninstall
	${RM} ${LOCALBASE}/man/mandesc

.include "../../mk/bsd.pkg.mk"
