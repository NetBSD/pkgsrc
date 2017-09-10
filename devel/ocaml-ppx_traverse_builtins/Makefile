# $NetBSD: Makefile,v 1.4 2017/09/10 05:55:47 dholland Exp $

VERSION=	0.9.0
GITHUB_PROJECT=	ppx_traverse_builtins
GITHUB_TAG=	v${VERSION}
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
PKGREVISION=	1
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
