# $NetBSD: Makefile,v 1.12 2022/05/24 18:51:50 jaapb Exp $

GITHUB_PROJECT=	ppx_derivers
DISTNAME=	${GITHUB_PROJECT}-1.2.1
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=diml/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/diml/ppx_derivers/
COMMENT=	Interoperation package for ocaml-ppx_deriving and ocaml-ppx_type_conv
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
