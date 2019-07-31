# $NetBSD: Makefile,v 1.2 2019/07/31 09:27:29 jaapb Exp $

GITHUB_PROJECT=	ppx_custom_printf
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.12.1
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ppx_custom_printf/
COMMENT=	Printf-style format-strings for user-defined string conversion
LICENSE=	mit

USE_LANGUAGES=	# none

OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../devel/ocaml-ppx_sexp_conv/buildlink3.mk"
.include "../../devel/ocaml-ppxlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
