# $NetBSD: Makefile,v 1.1 2017/03/14 13:12:28 wiz Exp $

DISTNAME=	leveldb-1.20
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	mishka@NetBSD.org
HOMEPAGE=	https://github.com/google/leveldb
COMMENT=	Fast and lightweight key/value database library by Google
LICENSE=	modified-bsd

USE_LANGUAGES+=	c c++
USE_TOOLS+=	gmake pax

INSTALLATION_DIRS+=	bin include/leveldb lib share/doc/leveldb

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
SS=		dylib
.else
SS=		so
.endif

MAJOR=		${PKGVERSION_NOREV:R}
MINOR=		${PKGVERSION_NOREV:E}

# N.B.: leveldb Darwin support follows popular Unix .so naming convention
SS.M=		${SS}.${MAJOR}
SS.M.N=		${SS}.${MAJOR}.${MINOR}

PLIST_SUBST+=	SS=${SS:Q} SS.M=${SS.M:Q} SS.M.N=${SS.M.N:Q}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/out-static/leveldbutil ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/out-static/db_bench 				\
		${DESTDIR}${PREFIX}/bin/leveldb_bench

	${INSTALL_LIB} ${WRKSRC}/out-static/libleveldb.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/out-shared/libleveldb.${SS.M.N} ${DESTDIR}${PREFIX}/lib
	${LN} -s libleveldb.${SS.M.N} ${DESTDIR}${PREFIX}/lib/libleveldb.${SS.M}
	${LN} -s libleveldb.${SS.M} ${DESTDIR}${PREFIX}/lib/libleveldb.${SS}

	${INSTALL_DATA} ${WRKSRC}/include/leveldb/*			\
		${DESTDIR}${PREFIX}/include/leveldb

	cd ${WRKSRC}/doc && ${PAX} -rw . ${DESTDIR}${PREFIX}/share/doc/leveldb

.include "options.mk"
.include "../../mk/bsd.pkg.mk"
