# $NetBSD: Makefile,v 1.10 2026/03/01 12:38:37 gdt Exp $

GITHUB_PROJECT=	ocaml-conduit
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-5.1.0
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mirage/ocaml-conduit/
COMMENT=	Dereference URIs into OCaml communication channels
LICENSE=	isc

USE_LANGUAGES=	# none

OCAML_USE_DUNE=		yes
DUNE_BUILD_PACKAGES=	conduit
OPAM_INSTALL_FILES=	${DUNE_BUILD_PACKAGES}
OCAML_FINDLIB_DIRS=	${DUNE_BUILD_PACKAGES}

.include "options.mk"
.include "../../devel/ocaml-astring/buildlink3.mk"
.include "../../devel/ocaml-logs/buildlink3.mk"
.include "../../devel/ocaml-ppx_sexp_conv/buildlink3.mk"
#.include "../../devel/ocaml-result/buildlink3.mk"
.include "../../devel/ocaml-sexplib/buildlink3.mk"
.include "../../net/ocaml-ipaddr/buildlink3.mk"
.include "../../www/ocaml-uri/buildlink3.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
