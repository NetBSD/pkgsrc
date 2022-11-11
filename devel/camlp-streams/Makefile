# $NetBSD: Makefile,v 1.1 2022/11/11 10:29:10 jaapb Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	camlp-streams-5.0.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml/camlp-streams/
COMMENT=	Ocaml stream parsing libraries for use with Camlp5
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c
OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
