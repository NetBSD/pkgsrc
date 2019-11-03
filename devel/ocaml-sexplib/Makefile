# $NetBSD: Makefile,v 1.21 2019/11/03 10:39:26 rillig Exp $

GITHUB_PROJECT=	sexplib
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.12.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/sexplib/
COMMENT=	S-Expressions with Type Converters for OCaml
LICENSE=	modified-bsd AND apache-2.0

OCAML_USE_FINDLIB=	yes
OCAML_USE_DUNE=		yes

BUILD_TARGET=	default

.include "../../devel/ocaml-parsexp/buildlink3.mk"
.include "../../devel/ocaml-sexplib0/buildlink3.mk"
.include "../../math/ocaml-num/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
