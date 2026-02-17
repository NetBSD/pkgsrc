# $NetBSD: Makefile,v 1.14 2026/02/17 13:39:03 wiz Exp $

GITHUB_PROJECT=	ppx_derivers
DISTNAME=	${GITHUB_PROJECT}-1.2.1
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=diml/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/diml/ppx_derivers/
COMMENT=	Interoperation package for ocaml-ppx_deriving and ocaml-ppx_type_conv
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
