# $NetBSD: Makefile,v 1.2 2020/01/16 14:28:31 jaapb Exp $

GITHUB_PROJECT=	ppx_module_timer
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.13.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ppx_module_timer/
COMMENT=	PPX rewriter that records top-level module startup times
LICENSE=	mit

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../devel/ocaml-ppx_base/buildlink3.mk"
.include "../../devel/ocaml-ppxlib/buildlink3.mk"
.include "../../devel/ocaml-stdio/buildlink3.mk"
.include "../../time/ocaml-time_now/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
