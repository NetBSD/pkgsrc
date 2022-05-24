# $NetBSD: Makefile,v 1.15 2022/05/24 18:51:51 jaapb Exp $

VERSION=	5.4.0
GITHUB_PROJECT=	ppx_tools_versioned
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml-ppx/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml-ppx/ppx_tools_versioned/
COMMENT=	Tools for authors of ppx rewriters
LICENSE=	x11

USE_LANGUAGES=	# none
USE_TOOLS=	gmake

OCAML_USE_FINDLIB=	yes
OCAML_USE_DUNE=		yes

.include "../../devel/ocaml-migrate-parsetree/buildlink3.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
