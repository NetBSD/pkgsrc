# $NetBSD: Makefile,v 1.7 2026/03/01 12:38:23 gdt Exp $

GITHUB_PROJECT=	encore
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.4
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mirage/encore/
COMMENT=	Library to generate ocaml-angstrom decoders and encoders
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-angstrom/buildlink3.mk"
.include "../../devel/ocaml-ke/buildlink3.mk"
.include "../../devel/ocaml-ocplib-endian/buildlink3.mk"
.include "../../devel/ocaml-fmt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
