# $NetBSD: Makefile,v 1.2 2017/09/08 09:51:22 jaapb Exp $

VERSION=	5.0.1
GITHUB_PROJECT=	ppx_tools_versioned
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
PKGREVISION=	1
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=let-def/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/let-def/ppx_tools_versioned/
COMMENT=	Tools for authors of ppx rewriters
LICENSE=	x11

USE_LANGUAGES=	# none
USE_TOOLS=	gmake

OCAML_USE_FINDLIB=	yes

.include "../../devel/ocaml-migrate-parsetree/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
