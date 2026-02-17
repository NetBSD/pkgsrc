# $NetBSD: Makefile,v 1.26 2026/02/17 13:39:07 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-0.15.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
GITHUB_PROJECT=	sexplib
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/sexplib/
COMMENT=	S-Expressions with Type Converters for OCaml
LICENSE=	modified-bsd AND apache-2.0

OCAML_USE_FINDLIB=	yes
OCAML_USE_DUNE=		yes

BUILD_TARGET=	default

.include "../../devel/ocaml-parsexp/buildlink3.mk"
.include "../../devel/ocaml-sexplib0/buildlink3.mk"
.include "../../math/ocaml-num/buildlink3.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
