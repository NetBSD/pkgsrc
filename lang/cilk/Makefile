# $NetBSD: Makefile,v 1.9 2003/06/02 01:19:06 jschauma Exp $

DISTNAME=		cilk-5.3.1
PKGREVISION=		2
CATEGORIES=		lang parallel
MASTER_SITES=		http://supertech.lcs.mit.edu/cilk/ \
			ftp://theory.lcs.mit.edu/pub/cilk/

MAINTAINER=		tech-pkg@netbsd.org
HOMEPAGE=		http://supertech.lcs.mit.edu/cilk/
COMMENT=		multithreaded parallel programming language based on ANSI C

GNU_CONFIGURE=		# defined
USE_BUILDLINK2=	 	# defined
USE_GMAKE=		# defined
USE_PERL5=		yes
USE_LIBTOOL=		yes
PTHREAD_OPTS+=		require

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
LTCONFIG_OVERRIDE= 	${WRKSRC}/ltconfig

INFO_FILES=		cilk-faq.info

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/cilk
	cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS COPYING			\
		FAQ/cilk-faq.ascii README THANKS doc/manual.ps		\
		${PREFIX}/share/doc/cilk
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/cilk
	cd ${WRKSRC}/examples && ${INSTALL_DATA} *.cilk *.c *.input	\
		${PREFIX}/share/examples/cilk
	${INSTALL_DATA} ${WRKSRC}/FAQ/cilk-faq.info ${PREFIX}/info

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
