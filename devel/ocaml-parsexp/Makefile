# $NetBSD: Makefile,v 1.1 2018/05/09 14:26:35 jaapb Exp $

GITHUB_PROJECT=	parsexp
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.11.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/parsexp/
COMMENT=	S-expression parsing library for OCaml
LICENSE=	apache-2.0

OCAML_USE_FINDLIB=	yes
OCAML_USE_JBUILDER=	yes
UNLIMIT_RESOURCES+=	stacksize # needed for very large constant

.include "../../devel/ocaml-sexplib0/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
