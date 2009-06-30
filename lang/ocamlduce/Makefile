# $NetBSD: Makefile,v 1.4 2009/06/30 00:07:18 joerg Exp $
#

DISTNAME=	ocamlduce-3.10.2
CATEGORIES=	lang
MASTER_SITES=	http://gallium.inria.fr/~frisch/ocamlcduce/download/

MAINTAINER=	jaapb@kerguelen.org
HOMEPAGE=	http://gallium.inria.fr/~frisch/ocamlcduce/
COMMENT=	Library to integrate XML features into OCaml

MAKE_JOBS_SAFE=		no

DEPENDS+=	ocaml-findlib-[0-9]*:../../devel/ocaml-findlib

USE_TOOLS+=	gmake
BUILD_TARGET=	all

.if (${MACHINE_ARCH} == "i386") || (${MACHINE_ARCH} == "powerpc") || \
    (${MACHINE_ARCH} == "sparc") || (${MACHINE_ARCH} == "x86_64")
MAKE_ENV+=	HAVE_OCAMLOPT=yes
BUILD_TARGET=	opt
INSTALL_TARGET=	install
PLIST_SRC+=	PLIST.opt
.endif

PLIST_SRC+=	PLIST

BUILDLINK_API_DEPENDS.ocaml+=	ocaml>=3.10.2

.include "../../lang/ocaml/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
