# $NetBSD: Makefile,v 1.1.1.1 2007/04/08 23:04:53 tonio Exp $
#

DISTNAME=	ocamlduce-3.09.3pl1
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

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
