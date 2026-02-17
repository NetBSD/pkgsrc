# $NetBSD: Makefile,v 1.6 2026/02/17 13:38:55 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-0.15.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
GITHUB_PROJECT=	base_bigstring
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/base_bigstring/
COMMENT=	OCaml string type based on Bigarray, for use in I/O and C bindings
LICENSE=	mit

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../devel/ocaml-int_repr/buildlink3.mk"
.include "../../devel/ocaml-ppx_jane/buildlink3.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
