# $NetBSD: Makefile,v 1.5 2017/09/10 05:53:02 dholland Exp $

VERSION=	1.0.1
PKGREVISION=	2
GITHUB_PROJECT=	ocaml-migrate-parsetree
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=let-def/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/let-def/ocaml-migrate-parsetree/
COMMENT=	Migrate parse trees between versions of OCaml
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c
OCAML_USE_FINDLIB=	yes
OCAML_FINDLIB_DIRS=	${GITHUB_PROJECT}
OCAML_USE_JBUILDER=	yes
OCAML_USE_OPAM=		yes
OPAM_INSTALL_FILES=	${GITHUB_PROJECT}

.include "../../mk/ocaml.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
