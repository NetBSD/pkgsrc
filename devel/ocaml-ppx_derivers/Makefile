# $NetBSD: Makefile,v 1.1 2017/09/08 11:59:54 jaapb Exp $

GITHUB_PROJECT=	ppx_derivers
DISTNAME=	${GITHUB_PROJECT}-1.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=diml/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/diml/ppx_derivers/
COMMENT=	Interoperation package for ocaml-ppx_deriving and ocaml-ppx_type_conv
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
OCAML_USE_JBUILDER=	yes

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
