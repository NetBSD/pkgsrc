# $NetBSD: Makefile,v 1.4 2018/04/04 19:34:44 jaapb Exp $

GITHUB_PROJECT=	ppx_derivers
DISTNAME=	${GITHUB_PROJECT}-1.0
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
PKGREVISION=	2
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=diml/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/diml/ppx_derivers/
COMMENT=	Interoperation package for ocaml-ppx_deriving and ocaml-ppx_type_conv
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
OCAML_USE_JBUILDER=	yes
OCAML_USE_OPAM=		yes

.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
