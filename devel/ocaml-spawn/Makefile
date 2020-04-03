# $NetBSD: Makefile,v 1.2 2020/04/03 10:56:09 jaapb Exp $

GITHUB_PROJECT=	spawn
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.13.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
DIST_SUBDIR=	ocaml-${GITHUB_PROJECT}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/spawn/
COMMENT=	Spawn sub-processes
LICENSE=	mit

OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-ppx_expect/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
