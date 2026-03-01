# $NetBSD: Makefile,v 1.7 2026/03/01 12:38:23 gdt Exp $

DISTNAME=	${GITHUB_PROJECT}-0.5
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}
GITHUB_PROJECT=	duff
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mirage/duff/
COMMENT=	Library to generate ocaml-angstrom decoders and encoders
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-fmt/buildlink3.mk"
.include "../../devel/ocaml-fpath/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
