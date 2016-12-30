# $NetBSD: Makefile,v 1.5 2016/12/30 11:16:59 jaapb Exp $

VERSION=	113.33.01
GITHUB_PROJECT=	ppx_sexp_conv
GITHUB_TAG=	${VERSION}+4.03
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ppx_sexp_conv/
COMMENT=	Generation of S-expression conversion functions from type definitions
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${DISTNAME}-4.03
HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none
OCAML_USE_FINDLIB=	yes

.include "../../devel/ocaml-oasis/buildlink3.mk"
.include "../../devel/ocaml-ppx_core/buildlink3.mk"
.include "../../devel/ocaml-ppx_type_conv/buildlink3.mk"
.include "../../devel/ocamlbuild/buildlink3.mk"
.include "../../misc/ocaml-opam/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
