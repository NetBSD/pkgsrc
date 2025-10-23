# $NetBSD: Makefile,v 1.30 2025/10/23 17:07:35 schmonz Exp $

DISTNAME=		cdb-20251021
CATEGORIES=		databases
MASTER_SITES=		${HOMEPAGE}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://cdb.cr.yp.to/
COMMENT=		Creates and reads constant databases
LICENSE=		public-domain

CONFLICTS+=		tinycdb-[0-9]*

FORCE_C_STD=		c99
CFLAGS.Linux+=		-D_XOPEN_SOURCE=500
INSTALLATION_DIRS=	bin include lib ${PKGMANDIR}/man1 ${PKGMANDIR}/man3
USE_TOOLS+=		diff

SUBST_CLASSES+=		for-test
SUBST_STAGE.for-test=	pre-test
SUBST_FILES.for-test=	cdb*make-*-for-test
SUBST_SED.for-test=	-e 's|${PREFIX}/bin/|${WRKSRC}/|'

post-build:
	cd ${WRKSRC};					\
	for i in cdb*make-12 cdb*make-sv; do		\
		${CP} $$i $$i-for-test;			\
	done

do-test:
	${RUN}${_ULIMIT_CMD} cd ${WRKSRC};		\
	./rts > rts.out;				\
	${DIFF} rts.exp rts.out

post-install:
	cd ${WRKSRC};							\
	${INSTALL_DATA} cdb.h ${DESTDIR}${PREFIX}/include/;		\
	${INSTALL_DATA} cdb.a ${DESTDIR}${PREFIX}/lib/libcdb.a;		\
	${INSTALL_DATA} cdb64.a ${DESTDIR}${PREFIX}/lib/libcdb64.a;	\
	cd doc/man;							\
	for i in *.3; do						\
		${INSTALL_MAN} $$i ${DESTDIR}${PREFIX}/${PKGMANDIR}/man3/;	\
	done;								\
	for i in *.1; do						\
		${INSTALL_MAN} $$i ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/;	\
	done

.include "../../mk/djbware.mk"
.include "../../mk/bsd.pkg.mk"
