# $NetBSD: Makefile,v 1.8 2018/11/12 16:10:22 jaapb Exp $

VERSION=	0.9.0
GITHUB_PROJECT=	ppx_traverse_builtins
GITHUB_TAG=	v${VERSION}
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
PKGREVISION=	5
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ppx_traverse_builtins/
COMMENT=	Builtin traversers for ppx_traverse
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

OCAML_USE_FINDLIB=	yes
OCAML_USE_JBUILDER=	yes
OCAML_USE_OPAM=		yes

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
