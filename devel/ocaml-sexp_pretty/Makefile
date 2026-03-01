# $NetBSD: Makefile,v 1.5 2026/03/01 12:38:32 gdt Exp $

DISTNAME=	${GITHUB_PROJECT}-0.15.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
GITHUB_PROJECT=	sexp_pretty
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/sexp_pretty/
COMMENT=	Pretty printer for S-Expressions
LICENSE=	mit

OCAML_USE_DUNE=		yes

BUILD_TARGET=	default

.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../devel/ocaml-ppx_base/buildlink3.mk"
.include "../../devel/ocaml-sexplib/buildlink3.mk"
.include "../../devel/ocaml-re/buildlink3.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
