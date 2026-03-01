# $NetBSD: Makefile,v 1.5 2026/03/01 12:38:30 gdt Exp $

DISTNAME=	${GITHUB_PROJECT}-0.15.0
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=janestreet/}
GITHUB_PROJECT=	ppx_log
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/janestreet/ppx_log/
COMMENT=	Extension nodes for lazily rendering log messages
LICENSE=	mit

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../devel/ocaml-ppx_here/buildlink3.mk"
.include "../../devel/ocaml-ppx_sexp_conv/buildlink3.mk"
.include "../../devel/ocaml-ppx_sexp_message/buildlink3.mk"
.include "../../devel/ocaml-ppxlib/buildlink3.mk"
.include "../../devel/ocaml-sexplib/buildlink3.mk"
.include "../../lang/ocaml/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
