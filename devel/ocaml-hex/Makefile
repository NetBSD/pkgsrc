# $NetBSD: Makefile,v 1.1 2019/03/19 12:56:46 jaapb Exp $

GITHUB_PROJECT=	ocaml-hex
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-1.3.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mirage/ocaml-hex/
COMMENT=	Hexadecimal converter for OCaml
LICENSE=	isc

USE_LANGUAGES=	# none

OCAML_USE_DUNE=	yes

.include "../../devel/ocaml-cstruct/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
