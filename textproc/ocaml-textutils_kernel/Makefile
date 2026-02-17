# $NetBSD: Makefile,v 1.4 2026/02/17 13:39:13 wiz Exp $

DISTNAME=	${GITHUB_PROJECT}-0.15.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
GITHUB_PROJECT=	textutils_kernel
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/textutils_kernel/
COMMENT=	Utility functions for dealing with text (kernel)
LICENSE=	mit

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-core/buildlink3.mk"
.include "../../devel/ocaml-ppx_jane/buildlink3.mk"
.include "../../textproc/ocaml-uutf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
