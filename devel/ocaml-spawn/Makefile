# $NetBSD: Makefile,v 1.8 2026/03/01 12:38:33 gdt Exp $

DISTNAME=	${GITHUB_PROJECT}-0.15.1
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
GITHUB_PROJECT=	spawn
GITHUB_TAG=	v${PKGVERSION_NOREV}
DIST_SUBDIR=	ocaml-${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/spawn/
COMMENT=	Spawn sub-processes
LICENSE=	mit

OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-ppx_expect/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
