# $NetBSD: Makefile,v 1.11 2019/03/05 18:21:04 jaapb Exp $

GITHUB_PROJECT=	yojson
DISTNAME=	${GITHUB_PROJECT}-1.7.0
PKGNAME=	ocaml-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=mjambon/}

MAINTAINER=	jaapb@NetBSD.org
HOMEPAGE=	https://github.com/mjambon/yojson/
COMMENT=	JSON parsing and pretty-printing library for OCaml
LICENSE=	modified-bsd

OCAML_USE_DUNE=	yes
INSTALLATION_DIRS+=	bin

.include "../../mk/ocaml.mk"
.include "../../devel/ocaml-biniou/buildlink3.mk"
.include "../../devel/ocaml-cppo/buildlink3.mk"
.include "../../textproc/ocaml-easy-format/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
