# $NetBSD: Makefile,v 1.4 2020/04/08 11:55:26 jaapb Exp $

GITHUB_PROJECT=	async
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.13.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/async/
COMMENT=	Asynchronous execution library from Jane Street
LICENSE=	mit

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-async_extra/buildlink3.mk"
.include "../../devel/ocaml-async_kernel/buildlink3.mk"
.include "../../devel/ocaml-async_unix/buildlink3.mk"
.include "../../devel/ocaml-core/buildlink3.mk"
.include "../../devel/ocaml-core_kernel/buildlink3.mk"
.include "../../devel/ocaml-ppx_jane/buildlink3.mk"
.include "../../textproc/ocaml-textutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
