# $NetBSD: Makefile,v 1.8 2011/12/02 22:45:47 cheusov Exp $
#

DISTNAME=	lmdbg-0.17.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lmdbg/} \
		http://mova.org/~cheusov/pub/lmdbg/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/lmdbg/
COMMENT=	Lightweight Modular malloc Debugger
LICENSE=	mit

BUILD_DEPENDS+=		mk-configure>=0.20.0:../../devel/mk-configure
DEPENDS+=		pipestatus-[0-9]*:../../devel/pipestatus
DEPENDS+=		runawk>=1.3.1:../../lang/runawk
#DEPENDS+=		gdb-[0-9]*:../../devel/gdb

ONLY_FOR_COMPILER=	gcc icc clang
NOT_FOR_PLATFORM=	Darwin-*-*

PKG_DESTDIR_SUPPORT=	user-destdir

TEST_TARGET=		test

DOCDIR=			share/doc/lmdbg
DOCFILES=		README NEWS ChangeLog

REPLACE_SH=		scripts/lmdbg*.in tests/test.sh

REPLACE_INTERPRETER+=	runawk
REPLACE.runawk.old=	.*runawk
REPLACE.runawk.new=	${PREFIX}/bin/runawk
REPLACE_FILES.runawk=	scripts/lmdbg-*.in

INSTALLATION_DIRS=	${DOCDIR}

MAKE_PROGRAM=	${PREFIX}/bin/mkcmake

post-install:
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${DOCDIR}
.endfor

.include "../../devel/mk-configure/configure.mk"
.include "../../devel/libjudy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
