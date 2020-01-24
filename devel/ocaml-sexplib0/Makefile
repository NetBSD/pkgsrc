# $NetBSD: Makefile,v 1.7 2020/01/24 16:15:30 jaapb Exp $

GITHUB_PROJECT=	sexplib0
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.13.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/sexplib0/
COMMENT=	Library with definition of S-expressions and some base converters
LICENSE=	apache-2.0

OCAML_USE_FINDLIB=	yes
OCAML_USE_DUNE=		yes

BUILD_TARGET=	default

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
