# $NetBSD: Makefile,v 1.19 2004/04/28 05:06:28 snj Exp $

DISTNAME=		cilk-5.3.1
PKGREVISION=		2
CATEGORIES=		lang parallel
MASTER_SITES=		http://supertech.lcs.mit.edu/cilk/ \
			ftp://theory.lcs.mit.edu/pub/cilk/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://supertech.lcs.mit.edu/cilk/
COMMENT=		Multithreaded parallel programming language based on ANSI C

ONLY_FOR_PLATFORM=	*-*-alpha *-*-i386 -*-*mipse[bl] *-*-powerpc *-*-sparc

GNU_CONFIGURE=		# defined
USE_BUILDLINK3=	 	yes
USE_GNU_TOOLS+=		make
USE_PERL5=		yes
USE_LIBTOOL=		yes
PTHREAD_OPTS+=		require

INFO_FILES=		cilk-faq.info

TEST_TARGET=		check

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cilk
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS COPYING			\
		FAQ/cilk-faq.ascii README THANKS doc/manual.ps		\
		${PREFIX}/share/doc/cilk
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cilk
	cd ${WRKSRC}/examples && ${INSTALL_DATA} *.cilk *.c *.input	\
		${PREFIX}/share/examples/cilk
	${INSTALL_DATA} ${WRKSRC}/FAQ/cilk-faq.info ${PREFIX}/info

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
