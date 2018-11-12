# $NetBSD: Makefile,v 1.7 2018/11/12 16:10:21 jaapb Exp $

GITHUB_PROJECT=	ppx_derivers
DISTNAME=	${GITHUB_PROJECT}-1.2
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
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
