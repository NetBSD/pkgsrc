# $NetBSD: Makefile,v 1.8 2022/05/24 18:59:22 jaapb Exp $

DISTNAME=	${GITHUB_PROJECT}-0.15.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
GITHUB_PROJECT=	async_unix
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/async_unix/
COMMENT=	Asynchronous execution library from Jane Street (unix)
LICENSE=	mit

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-async_kernel/buildlink3.mk"
.include "../../devel/ocaml-core/buildlink3.mk"
.include "../../devel/ocaml-core_kernel/buildlink3.mk"
.include "../../devel/ocaml-core_unix/buildlink3.mk"
.include "../../devel/ocaml-ppx_jane/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
