# $NetBSD: Makefile,v 1.12 2017/09/08 09:51:22 jaapb Exp $

GITHUB_PROJECT=	sexplib
GITHUB_TAG=	v${VERS}
DISTNAME=	${GITHUB_PROJECT}-${VERS}
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
VERS=		0.9.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/sexplib/
COMMENT=	S-Expressions with Type Converters for OCaml
LICENSE=	modified-bsd AND apache-2.0

OCAML_USE_FINDLIB=	yes
OCAML_USE_OPAM=	yes

BUILD_TARGET=	default

.include "../../devel/ocaml-jbuilder/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
