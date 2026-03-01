# $NetBSD: Makefile,v 1.8 2026/03/01 12:38:28 gdt Exp $

GITHUB_PROJECT=	ppx_cold
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.15.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ppx_cold/
COMMENT=	Cold path annotation translator for OCaml
LICENSE=	mit

USE_LANGUAGES=	# none

OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-ppxlib/buildlink3.mk"
.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
