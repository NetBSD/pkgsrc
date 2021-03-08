# $NetBSD: Makefile,v 1.4 2021/03/08 08:12:57 jaapb Exp $

GITHUB_PROJECT=	ppx_inline_test
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.14.1
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ppx_inline_test/
COMMENT=	Syntax extension for writing inline tests in OCaml code
LICENSE=	mit

USE_LANGUAGES=	# none

OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../devel/ocaml-ppxlib/buildlink3.mk"
.include "../../time/ocaml-time_now/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
