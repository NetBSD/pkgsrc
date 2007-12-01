# $NetBSD: Makefile,v 1.2 2007/12/01 14:48:28 tonio Exp $
#

DISTNAME=	ocamlduce-3.10.0
CATEGORIES=	lang
MASTER_SITES=	http://gallium.inria.fr/~frisch/ocamlcduce/download/

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://gallium.inria.fr/~frisch/ocamlcduce/
COMMENT=	Library to integrate XML features into OCaml

DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

USE_TOOLS+=	gmake
BUILD_TARGET=	all
PLIST_SRC+=	PLIST

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
MAKE_ENV+=	HAVE_OCAMLOPT=yes
BUILD_TARGET=	opt
INSTALL_TARGET=	install
PLIST_SRC+=	PLIST.opt
.endif

BUILDLINK_API_DEPENDS.ocaml+=	ocaml>=3.10

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
