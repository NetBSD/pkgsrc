# $NetBSD: Makefile,v 1.4 2001/11/14 14:47:55 agc Exp $

DISTNAME=		mercury-compiler-0.10.1
PKGNAME=		mercury-0.10.1
CATEGORIES=		lang
MASTER_SITES=		ftp://ftp.mercury.cs.mu.oz.au/pub/mercury/ \
			${MASTER_SITE_SUNSITE:=devel/lang/mercury/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.cs.mu.oz.au/mercury/
COMMENT=		modern logic/functional programming language

DEPENDS+=		boehm-gc>=5.3:../../devel/boehm-gc

GNU_CONFIGURE=		yes
USE_GMAKE=		yes

INFO_FILES=		mercury.info

BOEHM_GC_DIR_DEFAULT=	${LOCALBASE}
EVAL_PREFIX=		BOEHM_GC_DIR=boehm-gc
CONFIGURE_ENV+=		BOEHM_GC_DIR=${BOEHM_GC_DIR}

# Some of the scripts test CC and use special settings for gcc.
CONFIGURE_ENV+=		CC=gcc

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/mercury/lib/${MACHINE_ARCH}--${LOWER_OPSYS}
	${LN} -sf ${PREFIX}/lib/libgc.a \
		${PREFIX}/lib/mercury/lib/${MACHINE_ARCH}--${LOWER_OPSYS}/libgc.a
	${LN} -sf ${PREFIX}/include/gc.h ${PREFIX}/lib/mercury/inc/gc.h
	${FIND} ${WRKSRC} -type d -name "CVS" | ${XARGS} ${RM} -fr
	${FIND} ${WRKSRC} -type f -name ".cvsignore" | ${XARGS} ${RM} -f
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mercury
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${WRKSRC}/samples
	cd ${WRKSRC}/samples && ${PAX} -rw . ${PREFIX}/share/examples/mercury

.include "../../mk/bsd.pkg.mk"
