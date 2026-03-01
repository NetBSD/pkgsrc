# $NetBSD: Makefile,v 1.8 2026/03/01 12:38:27 gdt Exp $

DISTNAME=	${GITHUB_PROJECT}-1.2
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=OCamlPro/}
GITHUB_PROJECT=	ocplib-endian

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/OCamlPro/ocplib-endian/
COMMENT=	Optimised functions to read and write int16/32/64
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-cppo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
