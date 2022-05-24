# $NetBSD: Makefile,v 1.4 2022/05/24 18:59:21 jaapb Exp $

DISTNAME=	${GITHUB_PROJECT}-0.15.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=inhabitedtype/}
GITHUB_PROJECT=	angstrom

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/inhabitedtype/angstrom/
COMMENT=	Parser combinators for OCaml
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../lang/ocaml/ocaml.mk"
.include "../../devel/ocaml-async/buildlink3.mk"
.include "../../devel/ocaml-bigstringaf/buildlink3.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../devel/ocaml-result/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
