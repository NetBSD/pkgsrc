# $NetBSD: Makefile,v 1.2 2000/04/18 07:05:14 deberg Exp $
#

DISTNAME=	gnut-0.3.22
CATEGORIES=	net
MASTER_SITES=	http://www.umr.edu/~jjp/

MAINTAINER=	deberg@netbsd.org
HOMEPAGE=	http://www.umr.edu/~jjp/

# Sync these with devel/unproven-pthreads:
ONLY_FOR_PLATFORM=      NetBSD-*-i386 NetBSD-*-arm32 NetBSD-*-m68k

DEPENDS+=	unproven-pthreads-0.*:../../devel/unproven-pthreads

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=--with-mit-pthreads
CONFIGURE_ENV+=	CC=${LOCALBASE}/pthreads/bin/pgcc \
		CXX=${LOCALBASE}/pthreads/bin/pg++

GNUTDOCDIR=		${PREFIX}/share/doc/gnut

post-install:
	${MKDIR} ${GNUTDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/TUTORIAL ${GNUTDOCDIR}
	${INSTALL_DATA} ${WRKSRC}/gnutrc.sample ${GNUTDOCDIR}

.include "../../mk/bsd.pkg.mk"
