# $NetBSD: Makefile,v 1.1 2016/03/04 15:44:28 jaapb Exp $

VERSION=	113.24.00
GITHUB_PROJECT=	ppx_type_conv
DISTNAME=	${GITHUB_PROJECT}-${VERSION}
PKGNAME=	${GITHUB_PROJECT}-${DISTNAME}
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=janestreet/ppx_type_conv/}
COMMENT=	Support library for type-driven code generators
LICENSE=	apache-2.0

HAS_CONFIGURE=	yes
USE_LANGUAGES=	# none
OCAML_USE_OASIS_DYNRUN=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-ppx_deriving/buildlink3.mk"
.include "../../devel/ocaml-ppx_driver/buildlink3.mk"
.include "../../devel/ocaml-ppx_tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
