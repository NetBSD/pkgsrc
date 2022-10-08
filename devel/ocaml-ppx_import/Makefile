# $NetBSD: Makefile,v 1.1 2022/10/08 15:01:01 tonio Exp $

DISTNAME=	${GITHUB_PROJECT}-1.10.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml-ppx/}
GITHUB_PROJECT=	ppx_import
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	tonio@NetBSD.org
HOMEPAGE=	https://github.com/ocaml-ppx/ppx_import/
COMMENT=	Ocaml syntax extension to pull in types from compiled interface files
LICENSE=	mit

USE_LANGUAGES=	c
OCAML_USE_DUNE=	yes

.include "../../devel/ocaml-ppxlib/buildlink3.mk"
#.include "../../devel/ocaml-deriving/buildlink3.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
