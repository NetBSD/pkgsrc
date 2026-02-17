# $NetBSD: Makefile,v 1.19 2026/02/17 13:38:55 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-0.15.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
GITHUB_PROJECT=	base
GITHUB_TAG=	v${PKGVERSION_NOREV}
DIST_SUBDIR=	ocaml-${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/base/
COMMENT=	Alternative standard library for OCaml
LICENSE=	apache-2.0

OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-dune-configurator/buildlink3.mk"
.include "../../devel/ocaml-sexplib0/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
