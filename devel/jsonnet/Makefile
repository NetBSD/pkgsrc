# $NetBSD: Makefile,v 1.5 2019/08/13 18:04:28 seb Exp $

DISTNAME=	jsonnet-0.13.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=google/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://jsonnet.org/
COMMENT=	Domain specific configuration language
LICENSE=	apache-2.0

EXTRACT_USING=	bsdtar

USE_LANGUAGES=	c c++11

USE_TOOLS+=	gmake bash mktemp
REPLACE_BASH+=	examples/check.sh examples/terraform/check.sh
REPLACE_BASH+=	test_cmd/run_cmd_tests.sh
REPLACE_BASH+=	test_suite/run_tests.sh test_suite/run_fmt_tests.sh
REPLACE_BASH+=	test_suite/run_fmt_idempotence_tests.sh

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

TEST_TARGET=	test
TEST_ENV+=	MKTEMP=${TOOLS_PATH.mktemp}

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
	${INSTALL_PROGRAM} ${WRKSRC}/jsonnetfmt ${DESTDIR}${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
