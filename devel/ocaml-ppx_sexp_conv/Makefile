# $NetBSD: Makefile,v 1.3 2016/06/09 06:23:39 wiz Exp $

VERSION=	113.24.00
GITHUB_PROJECT=	ppx_sexp_conv
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ppx_sexp_conv/
COMMENT=	Generation of S-expression conversion functions from type definitions
LICENSE=	apache-2.0

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none

OCAML_USE_OASIS_DYNRUN=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-ppx_core/buildlink3.mk"
.include "../../devel/ocaml-ppx_type_conv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
