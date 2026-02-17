# $NetBSD: Makefile,v 1.5 2026/02/17 13:39:00 wiz Exp $

GITHUB_PROJECT=	ke
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.4
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mirage/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mirage/ke/
COMMENT=	Fast implementation of queue in OCaml
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-bigarray-compat/buildlink3.mk"
.include "../../devel/ocaml-fmt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
