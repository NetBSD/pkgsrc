# $NetBSD: Makefile,v 1.1 2017/10/11 13:57:15 jaapb Exp $

GITHUB_PROJECT=	ppx_enumerate
GITHUB_TAG=	v${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.9.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ppx_enumerate/
COMMENT=	Generate a list containing all values of a finite type
LICENSE=	apache-2.0

USE_LANGUAGES=	# none

OCAML_USE_JBUILDER=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-migrate-parsetree/buildlink3.mk"
.include "../../devel/ocaml-ppx_core/buildlink3.mk"
.include "../../devel/ocaml-ppx_driver/buildlink3.mk"
.include "../../devel/ocaml-ppx_metaquot/buildlink3.mk"
.include "../../devel/ocaml-ppx_type_conv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
