# $NetBSD: Makefile,v 1.50 2026/03/01 12:38:26 gdt Exp $
#

PKGREVISION= 2
.include "Makefile.common"

PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ocsigen.org/
COMMENT=	Cooperative threading library for OCaml

OCAML_FINDLIB_DIRS=	lwt stublibs
DUNE_BUILD_PACKAGES=	lwt

CFLAGS.SunOS+=	-D_POSIX_PTHREAD_SEMANTICS

MAKE_ENV+=	LWT_DISCOVER_ARGUMENTS="--use-pthread true --use-libev true --verbose"

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/libev/buildlink3.mk"
.include "../../devel/ocaml-cppo/buildlink3.mk"
.include "../../devel/ocaml-dune-configurator/buildlink3.mk"
.include "../../devel/ocaml-findlib/buildlink3.mk"
.include "../../devel/ocaml-ocplib-endian/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
