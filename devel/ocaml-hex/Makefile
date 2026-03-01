# $NetBSD: Makefile,v 1.7 2026/03/01 12:38:24 gdt Exp $

DISTNAME=	${GITHUB_PROJECT}-1.5.0
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}
GITHUB_PROJECT=	ocaml-hex
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mirage/ocaml-hex/
COMMENT=	Hexadecimal converter for OCaml
LICENSE=	isc

USE_LANGUAGES=	# none

OCAML_USE_DUNE=	yes

.include "../../devel/ocaml-cstruct/buildlink3.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
