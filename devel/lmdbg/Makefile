# $NetBSD: Makefile,v 1.5 2011/10/09 10:02:47 cheusov Exp $
#

DISTNAME=	lmdbg-0.16.0
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lmdbg/} \
		http://mova.org/~cheusov/pub/lmdbg/

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/lmdbg/
COMMENT=	Lightweight Modular malloc Debugger
LICENSE=	mit

BUILD_DEPENDS+=		mk-configure>=0.20.0:../../devel/mk-configure
DEPENDS+=		pipestatus-[0-9]*:../../devel/pipestatus
#DEPENDS+=		gdb-[0-9]*:../../devel/gdb

ONLY_FOR_COMPILER=	gcc icc
NOT_FOR_PLATFORM=	Darwin-*-*

PKG_DESTDIR_SUPPORT=	user-destdir

TEST_TARGET=		test

MAKE_ENV=		MANDIR=${PREFIX}/${PKGMANDIR}

DOCDIR=			share/doc/lmdbg
DOCFILES=		README NEWS ChangeLog

REPLACE_INTERPRETER+=	runawk
REPLACE.runawk.old=	.*runawk
REPLACE.runawk.new=	${PREFIX}/bin/runawk
REPLACE_FILES.runawk=	scripts/lmdbg-*.in
DEPENDS+=		runawk>=1.3.1:../../lang/runawk

INSTALLATION_DIRS=	${DOCDIR}

MAKE_PROGRAM=	${PREFIX}/bin/mkcmake

post-install:
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${DOCDIR}
.endfor

.include "../../devel/mk-configure/configure.mk"
.include "../../devel/libjudy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
