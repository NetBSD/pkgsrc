# $NetBSD: Makefile,v 1.5 2012/12/14 14:40:24 jaapb Exp $
#

DISTNAME=	js_of_ocaml-1.3.2
CATEGORIES=	devel
MASTER_SITES=	http://ocsigen.org/download/

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://ocsigen.org/js_of_ocaml/
COMMENT=	Compiler of OCaml bytecode to Javascript
LICENSE=	gnu-lgpl-v2

DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib
DEPENDS+=	ocaml-deriving-ocsigen>=0.3:../../devel/ocaml-deriving-ocsigen

USE_LANGUAGES=	c
USE_TOOLS=	gmake

MAKE_ENV=	BINDIR=${DESTDIR}${PREFIX}/bin DESTDIR=${DESTDIR} OCAML_SITELIBDIR=${PREFIX}/lib/ocaml/site-lib

INSTALLATION_DIRS=	lib/ocaml/site-lib

PLIST_VARS=	opt
.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
PLIST.opt=	yes
.endif

.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
