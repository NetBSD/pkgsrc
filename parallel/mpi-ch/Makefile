# $NetBSD: Makefile,v 1.1.1.1 1998/10/13 23:31:04 garbled Exp $

DISTNAME=		mpich
PKGNAME=		mpich-1.1.1
CATEGORIES=		parallel
MASTER_SITES=		ftp://ftp.mcs.anl.gov/pub/mpi/

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.mcs.anl.gov/mpi/mpich/index.html

DEPENDS+=		ssh-1.2.26:../../security/ssh

#this pkg needs x11!!

WRKSRC=			${WRKDIR}/mpich
ALL_TARGET=		ALL
USE_PERL5=		yes
HAS_CONFIGURE=		yes
USE_GMAKE=		yes
CONFIGURE_ARGS=		-prefix=${PREFIX} -arch=netbsd -comm=ch_p4
CONFIGURE_ARGS+=	-nof77 -make=gmake -mpe -rsh=ssh -opt=-O -nodevdebug

post-install:
	${RM} ${LOCALBASE}/mpiuninstall
	${RM} ${LOCALBASE}/man/mandesc

.include "../../mk/bsd.pkg.mk"
