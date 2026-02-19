# $NetBSD: Makefile,v 1.7 2026/02/19 07:38:13 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-0.15.1
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
GITHUB_PROJECT=	jst-config
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/jst-config/
COMMENT=	Compile-time configuration for Jane Street libraries
LICENSE=	mit

TOOL_DEPENDS+=	ocaml-dune-configurator-[0-9]*:../../devel/ocaml-dune-configurator

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../devel/ocaml-ppx_assert/buildlink3.mk"
.include "../../devel/ocaml-stdio/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
