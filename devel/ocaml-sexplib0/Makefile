# $NetBSD: Makefile,v 1.4 2018/11/27 14:45:05 jaapb Exp $

GITHUB_PROJECT=	sexplib0
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.11.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/sexplib0/
COMMENT=	Library with definition of S-expressions and some base converters
LICENSE=	apache-2.0

OCAML_USE_FINDLIB=	yes
OCAML_USE_DUNE=	yes

BUILD_TARGET=	default

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
