# $NetBSD: Makefile,v 1.12 2026/02/17 13:39:07 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-0.15.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
GITHUB_PROJECT=	sexplib0
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/sexplib0/
COMMENT=	Library with definition of S-expressions and some base converters
LICENSE=	apache-2.0

OCAML_USE_FINDLIB=	yes
OCAML_USE_DUNE=		yes

BUILD_TARGET=	default

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
