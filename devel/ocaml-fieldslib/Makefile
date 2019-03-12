# $NetBSD: Makefile,v 1.1 2019/03/12 18:16:18 jaapb Exp $

GITHUB_PROJECT=	fieldslib
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.12.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/fieldslib/
COMMENT=	OCaml record fields as first-class values
LICENSE=	mit

OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
