# $NetBSD: Makefile,v 1.42 2020/04/21 11:29:59 jaapb Exp $
#

.include "Makefile.common"

PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	http://www.ocsigen.org/
COMMENT=	Cooperative threading library for OCaml

OCAML_FINDLIB_DIRS=	lwt stublibs
DUNE_BUILD_PACKAGES=	lwt

CFLAGS.SunOS+=	-D_POSIX_PTHREAD_SEMANTICS

MAKE_ENV+=	LWT_DISCOVER_ARGUMENTS="--use-pthread true --use-libev true --verbose"

.include "../../mk/ocaml.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/libev/buildlink3.mk"
.include "../../devel/ocaml-cppo/buildlink3.mk"
.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../devel/ocaml-migrate-parsetree/buildlink3.mk"
.include "../../devel/ocaml-mmap/buildlink3.mk"
.include "../../devel/ocaml-ocplib-endian/buildlink3.mk"
.include "../../devel/ocaml-ppx_tools_versioned/buildlink3.mk"
.include "../../devel/ocaml-result/buildlink3.mk"
.include "../../devel/ocaml-seq/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
