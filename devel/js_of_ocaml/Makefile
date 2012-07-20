# $NetBSD: Makefile,v 1.2 2012/07/20 20:08:25 wiz Exp $
#

DISTNAME=	js_of_ocaml-1.2
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://ocsigen.org/download/

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://ocsigen.org/js_of_ocaml/
COMMENT=	Compiler of OCaml bytecode to Javascript
LICENSE=	gnu-lgpl-v2

# remove on next update
DIST_SUBDIR=	js_of_ocaml-1.2

DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib
DEPENDS+=	ocaml-lwt>=2.3.0:../../devel/ocaml-lwt
DEPENDS+=	ocaml-deriving-ocsigen>=0.3:../../devel/ocaml-deriving-ocsigen

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c
USE_TOOLS=	gmake

MAKE_ENV=	BINDIR=${DESTDIR}${PREFIX}/bin DESTDIR=${DESTDIR} OCAML_SITELIBDIR=${PREFIX}/lib/ocaml/site-lib

PLIST_VARS=	opt
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
PLIST.opt=	yes
.endif

pre-install:
	${MKDIR} ${DESTDIR}${PREFIX}/lib/ocaml/site-lib

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
