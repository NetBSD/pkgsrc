# $NetBSD: Makefile,v 1.15 2015/01/04 02:47:06 dholland Exp $
#

DISTNAME=	lmdbg-1.2.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lmdbg/} \
		http://mova.org/~cheusov/pub/lmdbg/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/lmdbg/
COMMENT=	Lightweight Modular malloc Debugger
LICENSE=	mit

BUILD_DEPENDS+=		mk-configure>=0.24.0:../../devel/mk-configure
DEPENDS+=		pipestatus-[0-9]*:../../devel/pipestatus
DEPENDS+=		runawk>=1.3.1:../../lang/runawk
#DEPENDS+=		gdb-[0-9]*:../../devel/gdb

ONLY_FOR_COMPILER=	gcc icc clang
BROKEN_ON_PLATFORM=	Darwin-*-*

TEST_TARGET=		test

REPLACE_SH=		scripts/lmdbg*.in tests/test.sh

REPLACE_INTERPRETER+=	runawk
REPLACE.runawk.old=	.*runawk
REPLACE.runawk.new=	${PREFIX}/bin/runawk
REPLACE_FILES.runawk=	scripts/lmdbg-*.in

MAKE_ENV+=		AWK=${AWK:Q}

post-install:
	cd ${WRKSRC} && \
	${MAKE_ENV} ${MAKE_PROGRAM} ${INSTALL_MAKE_FLAGS} install-doc

.include "../../devel/mk-configure/mk-c.mk"
.include "../../devel/libjudy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
