# $NetBSD: Makefile,v 1.4 2020/04/08 09:41:35 jaapb Exp $

GITHUB_PROJECT=	async_rpc_kernel
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.13.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/async_rpc_kernel/
COMMENT=	Platform-independent core of Async RPC library
LICENSE=	mit

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-async_kernel/buildlink3.mk"
.include "../../devel/ocaml-core_kernel/buildlink3.mk"
.include "../../devel/ocaml-ppx_jane/buildlink3.mk"
.include "../../net/ocaml-protocol_version_header/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
