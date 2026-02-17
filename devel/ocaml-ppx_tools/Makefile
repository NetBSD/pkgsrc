# $NetBSD: Makefile,v 1.22 2026/02/17 13:39:05 wiz Exp $

VERSION=	6.5
GITHUB_PROJECT=	ppx_tools
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml-ppx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ocaml-ppx/ppx_tools/
COMMENT=	Tools for authors of OCaml ppx rewriters
LICENSE=	mit

USE_LANGUAGES=		# none

OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-cppo/buildlink3.mk"
BUILDLINK_DEPMETHOD.ocaml-cppo=	build
.include "../../mk/bsd.pkg.mk"
