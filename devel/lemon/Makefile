# $NetBSD: Makefile,v 1.6 2018/09/17 16:14:07 adam Exp $

.include "../../databases/sqlite3/Makefile.common"

LEMON_VERSION=	1.0

# Concatenate versions of lemon and sqlite3
# The reasoning for it is as follows:
# - currently lemon is an integral part of sqlite3
# - lemon has its own conservative versioning regardless of changes in its code
# - leave room for possible standalone lemon package with bumped versions
# - reflect reality and make it human readable without checking the sources

PKGNAME=	lemon-${LEMON_VERSION}.${SQLITE3_VERSION}
DISTNAME=	sqlite-src-${SQLITE3_DISTVERSION}
CATEGORIES=	devel
EXTRACT_SUFX=	.zip

MAINTAINER=	airhead@users.sf.net
HOMEPAGE=	http://www.hwaci.com/sw/lemon/
COMMENT=	Simple LALR(1) parser generator

CHECK_PORTABILITY_SKIP=	configure
INSTALLATION_DIRS=	bin share/lemon share/doc/lemon

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	lemon.c
SUBST_SED.paths+=	-e 's,"lempar.c","${PREFIX}/share/lemon/lempar.c",g'
SUBST_STAGE.paths=	pre-configure

do-build:
	cd ${WRKSRC}/tool && ${CC} ${CFLAGS} ${LDFLAGS} lemon.c -o lemon

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tool/lemon ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tool/lempar.c ${DESTDIR}${PREFIX}/share/lemon
	${INSTALL_DATA} ${WRKSRC}/doc/lemon.html ${DESTDIR}${PREFIX}/share/doc/lemon

.include "../../mk/bsd.pkg.mk"
