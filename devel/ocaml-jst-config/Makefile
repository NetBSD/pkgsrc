# $NetBSD: Makefile,v 1.8 2026/03/01 12:38:25 gdt Exp $

DISTNAME=	${GITHUB_PROJECT}-0.15.1
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
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
