# $NetBSD: Makefile,v 1.4 2026/03/01 12:38:19 gdt Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	camlp-streams-5.0.1
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ocaml/camlp-streams/
COMMENT=	Ocaml stream parsing libraries for use with Camlp5
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	c
OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
