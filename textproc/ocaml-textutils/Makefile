# $NetBSD: Makefile,v 1.7 2022/05/24 18:59:35 jaapb Exp $

DISTNAME=	${GITHUB_PROJECT}-0.15.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
GITHUB_PROJECT=	textutils
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/textutils/
COMMENT=	Utility functions for dealing with text
LICENSE=	mit

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-core/buildlink3.mk"
.include "../../devel/ocaml-core_kernel/buildlink3.mk"
.include "../../devel/ocaml-core_unix/buildlink3.mk"
.include "../../devel/ocaml-ppx_jane/buildlink3.mk"
.include "../../textproc/ocaml-textutils_kernel/buildlink3.mk"
.include "../../textproc/ocaml-uutf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
