# $NetBSD: Makefile,v 1.12 2026/03/01 12:38:22 gdt Exp $

DISTNAME=	${GITHUB_PROJECT}-0.15.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
GITHUB_PROJECT=	core_kernel
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/core_kernel/
COMMENT=	OCaml standard library overlay (kernel)
LICENSE=	mit

USE_TOOLS+=	bash
USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../devel/ocaml-core/buildlink3.mk"
.include "../../devel/ocaml-int_repr/buildlink3.mk"
.include "../../devel/ocaml-ppx_jane/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
