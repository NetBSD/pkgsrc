# $NetBSD: Makefile,v 1.1.1.1 2012/05/14 09:20:39 wiz Exp $
#

DISTNAME=	ocaml-sqlite3-1.6.1
CATEGORIES=	databases
MASTER_SITES=	http://www.ocaml.info/ocaml_sources/

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://www.ocaml.info/home/ocaml_sources.html
COMMENT=	Sqlite bindings for OCaml
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake autoconf
BUILD_TARGET=	docs bytecode

MAKE_ENV+=	OCAML_SITELIBDIR="${PREFIX}/lib/ocaml/site-lib"
MAKE_JOBS_SAFE=	no

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
PLIST_SRC+=	PLIST.opt
BUILD_TARGET+=	opt sqlite3.cmxs
.endif

PLIST_SRC+=	PLIST

pre-configure:
	cd ${WRKSRC} && autoconf

.include "../../lang/ocaml/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
