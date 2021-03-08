# $NetBSD: Makefile,v 1.2 2021/03/08 08:12:47 jaapb Exp $

GITHUB_PROJECT=	angstrom
DISTNAME=	${GITHUB_PROJECT}-0.11.1
PKGNAME=	ocaml-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=inhabitedtype/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/inhabitedtype/angstrom/
COMMENT=	Parser combinators for OCaml
LICENSE=	modified-bsd

USE_LANGUAGES=	# none
OCAML_USE_DUNE=	yes

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-async/buildlink3.mk"
.include "../../devel/ocaml-bigstringaf/buildlink3.mk"
.include "../../devel/ocaml-lwt/buildlink3.mk"
.include "../../devel/ocaml-result/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
