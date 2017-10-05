# $NetBSD: Makefile,v 1.1 2017/10/05 19:40:35 seb Exp $

DISTNAME=	v0.9.4
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME:S/v//}
#PKGREVISION=	1
CATEGORIES=	devel local
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jsonnet.org/
COMMENT=	Domain specific configuration language
LICENSE=	apache-2.0

EXTRACT_USING=	gtar

GITHUB_PROJECT=	jsonnet
DIST_SUBDIR=	${GITHUB_PROJECT}

USE_LANGUAGES=	c c++11

USE_TOOLS+=	gmake bash
REPLACE_BASH+=	examples/check.sh examples/terraform/check.sh
REPLACE_BASH+=	test_suite/run_tests.sh test_suite/run_fmt_tests.sh

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

TEST_TARGET=	test

INSTALLATION_DIRS=	lib include bin

# nothing to configure but REPLACE_BASH to apply
do-configure:
	@${DO_NADA}

do-install:
	${INSTALL_LIB} ${WRKSRC}/libjsonnet.so ${DESTDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libjsonnet++.so ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/include/libjsonnet.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/include/libjsonnet++.h ${DESTDIR}${PREFIX}/include
	${INSTALL_PROGRAM} ${WRKSRC}/jsonnet ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
