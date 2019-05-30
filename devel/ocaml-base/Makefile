# $NetBSD: Makefile,v 1.11 2019/05/30 09:22:35 jaapb Exp $

GITHUB_PROJECT=	base
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.12.2
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
DIST_SUBDIR=	ocaml-${GITHUB_PROJECT}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/base/
COMMENT=	Alternative standard library for OCaml
LICENSE=	apache-2.0

OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-sexplib0/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
