# $NetBSD: Makefile,v 1.1.1.1 2000/04/15 05:17:42 kim Exp $
#

DISTNAME=		gnut-0.3.21
CATEGORIES=		net
MASTER_SITES=		http://www.umr.edu/~jjp/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.umr.edu/~jjp/

DEPENDS+=		unproven-pthreads-*:../../devel/unproven-pthreads

GNU_CONFIGURE=		yes

CONFIGURE_ENV+=		CC=${LOCALBASE}/pthreads/bin/pgcc

GNUTDOCDIR=		${PREFIX}/share/doc/gnut

post-install:
	${MKDIR} ${GNUTDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/TUTORIAL ${GNUTDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/gnutrc.sample ${GNUTDOCDIR}

.include "../../mk/bsd.pkg.mk"
