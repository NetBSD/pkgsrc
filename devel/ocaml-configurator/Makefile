# $NetBSD: Makefile,v 1.1 2017/10/16 08:38:27 jaapb Exp $

GITHUB_PROJECT=	configurator
DISTNAME=	${GITHUB_PROJECT}-0.9.1
PKGNAME=	ocaml-${DISTNAME}
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/configurator/
COMMENT=	Helper library for gathering system configuration
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
USE_TOOLS+=	gmake
OCAML_USE_JBUILDER=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../devel/ocaml-ppx_base/buildlink3.mk"
.include "../../devel/ocaml-ppx_driver/buildlink3.mk"
.include "../../devel/ocaml-stdio/buildlink3.mk"
.include "../../devel/ocaml-migrate-parsetree/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
