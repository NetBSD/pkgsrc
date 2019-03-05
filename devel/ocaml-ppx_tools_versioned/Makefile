# $NetBSD: Makefile,v 1.8 2019/03/05 16:35:29 jaapb Exp $

VERSION=	5.2.1
GITHUB_PROJECT=	ppx_tools_versioned
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=let-def/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/let-def/ppx_tools_versioned/
COMMENT=	Tools for authors of ppx rewriters
LICENSE=	x11

USE_LANGUAGES=	# none
USE_TOOLS=	gmake

OCAML_USE_FINDLIB=	yes
OCAML_USE_DUNE=	yes

.include "../../devel/ocaml-migrate-parsetree/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
