# $NetBSD: Makefile,v 1.1 2018/05/09 14:46:59 jaapb Exp $

GITHUB_PROJECT=	ppxlib
GITHUB_TAG=	${PKGVERSION_NOREV}
DISTNAME=	${GITHUB_PROJECT}-0.3.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=ocaml-ppx/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/ocaml-ppx/ppxlib/
COMMENT=	Base library and tools for ppx rewriters
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
OCAML_USE_JBUILDER=	yes

.include "../../devel/ocaml-base/buildlink3.mk"
.include "../../devel/ocaml-compiler-libs/buildlink3.mk"
.include "../../devel/ocaml-migrate-parsetree/buildlink3.mk"
.include "../../devel/ocaml-ppx_derivers/buildlink3.mk"
.include "../../devel/ocaml-stdio/buildlink3.mk"
.include "../../mk/ocaml.mk"
.include "../../mk/bsd.pkg.mk"
