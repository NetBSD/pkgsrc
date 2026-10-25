# $NetBSD: Makefile,v 1.2 2026/10/25 01:42:59 alnsn Exp $

DISTNAME=	${GITHUB_PROJECT}-3.9.1
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml-ppx/}
GITHUB_PROJECT=	ppx_deriving_yojson
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ocaml-ppx/ppx_deriving_yojson/
COMMENT=	Yojson codec generator for OCaml
LICENSE=	mit

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

TEST_DEPENDS+=	ocaml-ounit2-[0-9]*:../../devel/ocaml-ounit2
TEST_TARGET=	test

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-ppx_deriving/buildlink3.mk"
.include "../../devel/ocaml-ppxlib/buildlink3.mk"
.include "../../devel/ocaml-yojson/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
