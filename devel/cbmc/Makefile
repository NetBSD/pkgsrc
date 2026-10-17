# $NetBSD: Makefile,v 1.1 2026/10/17 16:55:46 alnsn Exp $

DISTNAME=	cbmc-6.10.0
GITHUB_TAG=	cbmc-${PKGVERSION_NOREV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=diffblue/}
DISTFILES=	${DEFAULT_DISTFILES} minisat2_2.2.1.orig.tar.gz
SITES.minisat2_2.2.1.orig.tar.gz=	${MASTER_SITE_DEBIAN:=pool/main/m/minisat2/}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.cprover.org/cbmc/
COMMENT=	Bounded Model Checker for C and C++ programs
LICENSE=	original-bsd

USE_TOOLS+=		flex bison bash gmake perl git
USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++17 filesystem

CMAKE_CONFIGURE_ARGS+=	-DWITH_JBMC=OFF

EGDIR=			${PREFIX}/share/examples/cbmc
CONF_FILES+=		${EGDIR}/bash_completion.d/cbmc \
			${PKG_SYSCONFDIR}/bash_completion.d/cbmc
OWN_DIRS+=		${PKG_SYSCONFDIR}/bash_completion.d
INSTALLATION_DIRS+=	${EGDIR}/bash_completion.d

TEST_TARGET=		test
TEST_DEPENDS+=		z3-[0-9]*:../../math/z3
TEST_DEPENDS+=		cvc5-[0-9]*:../../math/cvc5

post-extract:
	${MKDIR} ${WRKSRC}/${CMAKE_BUILD_DIR}/minisat2-download/minisat2-download-prefix/src
	${CP} -p ${DISTDIR}/minisat2_2.2.1.orig.tar.gz \
		${WRKSRC}/${CMAKE_BUILD_DIR}/minisat2-download/minisat2-download-prefix/src/

post-install:
	${MV} ${DESTDIR}${PREFIX}/etc/bash_completion.d/cbmc \
		${DESTDIR}${EGDIR}/bash_completion.d/cbmc
	${RMDIR} ${DESTDIR}${PREFIX}/etc/bash_completion.d

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
